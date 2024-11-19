#include <cannon_data_provider.hpp>

namespace Nos3
{
    REGISTER_DATA_PROVIDER(CANNONDataProvider,"CANNON_PROVIDER");

    extern ItcLogger::Logger *sim_logger;

    CANNONDataProvider::CANNONDataProvider(const boost::property_tree::ptree& config) : SimIDataProvider(config)
    {
        sim_logger->trace("CANNONDataProvider::CANNONDataProvider:  Constructor executed");
        _request_count = 0;
    }

    boost::shared_ptr<SimIDataPoint> CANNONDataProvider::get_data_point(void) const
    {
        sim_logger->trace("CANNONDataProvider::get_data_point:  Executed");

        /* Prepare the provider data */
        _request_count++;

        /* Request a data point */
        SimIDataPoint *dp = new CANNONDataPoint(_request_count);

        /* Return the data point */
        return boost::shared_ptr<SimIDataPoint>(dp);
    }
}
