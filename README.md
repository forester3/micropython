# MicroPython branch: f7disc-lcd  

This branch contains LCD module to control STM32F746G-discovery only.

Current supported board is only STM32F746G-Discovery.

## How to build

```
git clone -b f7disc-lcd https://github.com/forester3/micropython.git
cd micropython
git submodule update --init
cd ports/stm32
make BOARD=STM32F7DISC
```

## How to deploy using on board ST-LINK

```
make BOARD=STM32F7DISC deploy-stlink
```

Note that MicroPython is licenced under the MIT license, and all contributions should follow this license.  
And LCD module is based on BSP driver by STMicroelectronics,  
its library licences is under  
* STMicro Mix Liberty + OSS + 3rd- party V1 - SOFTWARE LICENSE AGREEMENT  
  http://www.st.com/resource/en/license_agreement/dm00218346.pdf
