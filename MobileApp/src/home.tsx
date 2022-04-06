import React from 'react';
import {View, Text} from 'react-native';
import axios from 'axios';
import {LineChart} from 'react-native-chart-kit';
import {width} from 'react-native-dimension';

async function getData(previousData: number): Promise<any[] | undefined> {
  try {
    const res = await axios.get(
      `https://kent-iot-api.nathanm.fr/api/sensors?sort=updatedAt:desc&filters&pagination[limit]=${previousData}`,
      {
        headers: {
          Authorization:
            'Bearer c617ccebb4b01836a9da70d9c63040d14600f001c054721ff9c6dd1d16cadc8f328c9bd2984c5ad0bb4a57cdcd5aef79502e93013160e0077b1ce95722f74426c9c76471097097fec91daf6efffd5d10a54343535b67b3f12b31b6da96339ce951f31c1647b211977f2b921d7429bc57acae90732fb82ef4494f5207f140096e',
        },
      },
    );
    return res.data.data;
  } catch (error) {
    console.error(error);
    return undefined;
  }
}

export class Chart extends React.Component {
  constructor(props: any) {
    super(props);
  }

  state = {
    humidity: [0],
    temperature: [0],
    heatIndex: [0],
  };

  refreshData = async () => {
    const data = await getData(this.props.previousData);

    const humidity: Array<any> = [];
    const temperature: Array<any> = [];
    const heatIndex: Array<any> = [];

    data?.forEach(value => {
      humidity.unshift(value.attributes.humidity);
      temperature.unshift(value.attributes.temperature);
      heatIndex.unshift(value.attributes.heatIndex);
    });
    this.setState({
      humidity: humidity,
      temperature: temperature,
      heatIndex: heatIndex,
    });
  };

  componentDidMount() {
    this.refreshData();
    setInterval(this.refreshData, 5000);
    console.info('mounted', this.props);
  }

  render() {
    const chartConfig = {
      backgroundGradientFrom: '#1E2923',
      backgroundGradientFromOpacity: 0,
      backgroundGradientTo: '#08130D',
      backgroundGradientToOpacity: 0.5,
      color: () => 'black',
      strokeWidth: 2, // optional, default 3
      barPercentage: 0.5,
      useShadowColorFromDataset: false, // optional
    };
    const data = {
      datasets: [
        {
          data: this.state.humidity,
          color: () => 'blue',
        },
        {
          data: this.state.temperature,
          color: () => 'orange',
        },
        {
          data: this.state.heatIndex,
          color: () => 'red',
        },
      ],
      legend: ['Humidity', 'Temperature', 'Heat Index'],
    };
    return (
      <View style={{alignItems: 'center'}}>
        <Text>{this.props.name} ({this.props.previousData} samples)</Text>
        <LineChart
          data={data}
          width={width(100)}
          height={256}
          verticalLabelRotation={30}
          chartConfig={chartConfig}
          bezier
          fromZero={this.props.fromZero}
        />
      </View>
    );
  }
}
