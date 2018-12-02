#include "Vehicles.h"


Vehicles::Vehicles(): GameObject()
{
       type = 0;
}

Vehicles::~Vehicles()
{
        std::cout << "Vehicle destroyed." << std::endl ;

}
