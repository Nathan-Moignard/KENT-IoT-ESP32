module.exports = ({ env }) => ({
  auth: {
    secret: env('ADMIN_JWT_SECRET', 'e676862a295177d1d3250ce411032c93'),
  },
});
