# GY85 (Fake) Library

This library is intended to be used on raspberry pico with GY85 modules that can be found on [AliExpress](https://www.aliexpress.com/item/1005005777422028.html).
In particular this module has the following sensors:
- ADXL345: Accellerometer at 0x53
- ITG3205: Gyroscope at 0x68
- QMC5883L: Magnetometer at 0x0D (original module has HMC5883L)

## Features

Every sensor has theese main functions:
- init(): Initialize all sensors
- read(): Reads all sensors data and stores it to the gy85 object
- calibrate(): Calibrates accellerometer and gyroscope by calculating some samples
- set_xxx_sleep() : Turns sensor xxx into sleep mode 
- set_xxx_interrupt() : Enables/Disables sensor xxx interrupts


## Usage

To use this library in your Raspberry Pico project, follow these steps:

1. Clone the repository: 
```bash 
git clone https://github.com/mattsays/gy85.git
```
2. Copy the library files to your project directory.
3. Include the library in your cmake project
```cmake
project(gy85_example C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(path_to_library)

target_include_directories(gy85_example PRIVATE
  path_to_library
)

target_link_libraries(gy85_example
        gy85
        pico_stdlib
        hardware_i2c)

pico_add_extra_outputs(gy85_example)
```
4. Include the library in your code: `#include "gy85.hpp"`

I also wrote a [simple example](https://github.com/mattsays/gy85/blob/main/gy85_example.cpp) on how to use this library

## Contributing

Contributions are welcome! If you have any ideas, bug reports, or feature requests, please open an issue or submit a pull request on the [GitHub repository](https://github.com/mattsays/gy85/pulls).

## License

This library is licensed under the [MIT License](https://opensource.org/licenses/MIT). See the [LICENSE](https://github.com/mattsays/gy85/blob/main/LICENSE) file for more details.
