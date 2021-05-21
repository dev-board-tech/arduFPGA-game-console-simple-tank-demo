# arduFPGA-game-console-simple-tank-demo
 A simple micro tank controller using arduFPGA-game-console

 This a very simple micro tank controller and is a demo to in combination with other designs and applications demonstrate the possibility for arduFPGA-game-console to change the designs and application running at a given time.

 I use an arduFPGA game console as the "brain" of the thing, a FREENOVE command/driver board, a ROBOTIS BIOLOID remote control, a servomotor and a cheap ultrasound distance sensor.

The communication between arduFPGA and FREENOVE command/driver board is done thru a TWI interface.

The remote commands are received by the arduFPGA using an UART module.

Both communication are done thru arduFPGA onboard USB connector.

A simplified representation of the block schematick:

![arduFPGA-game-console-mini-tank-controller-block-sch](https://raw.githubusercontent.com/dev-board-tech/arduFPGA-game-console-simple-tank-demo/main/sch_block/arduFPGA-game-console_simple_tank_controller_sch_block.png)

A small video:
<div align="center">
  <a href="https://www.youtube.com/watch?v=gQMlpMnd5RA"><img src="https://img.youtube.com/vi/gQMlpMnd5RA/0.jpg" alt="IMAGE ALT TEXT"></a>
</div>
