import React from 'react';
import {SafeAreaView, ScrollView} from 'react-native';
import {Chart} from './src/home';

const App = () => {
  return (
    <SafeAreaView>
      <ScrollView contentInsetAdjustmentBehavior="automatic">
        <Chart name="Sensor Overview" previousData={10} fromZero={true} />
        <Chart name="Sensor Overview" previousData={50} fromZero={false} />
        <Chart name="Sensor Overview" previousData={100} fromZero={false} />
      </ScrollView>
    </SafeAreaView>
  );
};

export default App;
