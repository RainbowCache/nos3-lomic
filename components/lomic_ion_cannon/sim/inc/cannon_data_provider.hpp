#ifndef NOS3_CANNONDATAPROVIDER_HPP
#define NOS3_CANNONDATAPROVIDER_HPP

#include <boost/property_tree/xml_parser.hpp>
#include <ItcLogger/Logger.hpp>
#include <cannon_data_point.hpp>
#include <sim_i_data_provider.hpp>

namespace Nos3
{
    class CANNONDataProvider : public SimIDataProvider
    {
    public:
        /* Constructors */
        CANNONDataProvider(const boost::property_tree::ptree& config);

        /* Accessors */
        boost::shared_ptr<SimIDataPoint> get_data_point(void) const;

    private:
        /* Disallow these */
        ~CANNONDataProvider(void) {};
        CANNONDataProvider& operator=(const CANNONDataProvider&) {return *this;};

        mutable double _request_count;
    };
}

#endif
