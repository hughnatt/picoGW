# Utility tools for monitoring LoRa traffic using Semtech picoGW

This repository is composed of two sub-projects.

### Broker
Packet forwarder and utility tools provided by Semtech (see links below)

### Server
A simple NodeJS server displaying the messages received from the picoGW


## Docker
For easy use, you can launch the complete environment with the following command  
docker-compose up
Make sure you have docker-ce and docker-compose installed


## Known issues
Currently, the docker-compose script will only work if the pico gateway is
connected as /dev/ttyACM0. We are working on a fix to provide a way to connect
it through a different port.

## More information:  
https://github.com/Lora-net/picoGW_packet_forwarder  
https://github.com/Lora-net/picogw_hal  
