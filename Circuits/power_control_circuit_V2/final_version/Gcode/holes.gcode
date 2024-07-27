; This gcode is generated by my specialised python script for my PCB manufacturer project :))

; Machine Initialization Sequence...

G21 ; to set metric units
G90 ; to set absolute mode , G91 for incremental mode
G94 ; To set the active feed rate mode to units per minute mode

M5 ; disabling spindle PWM
C0 ; Choosing the empty tool slot in the multiplexer circuits

B1 ; Turn ON Machine

$H ; Homing :)
G10 P0 L20 X0.0Y0.0Z0.0 ; Force Reset current coordinates after homing


; The following gcode is the PCB holes drill gcode

; Getting and Activating Tool-2, The Tool.Spindle
G00X165.0Y91.0Z12.0 ; Go to Tool-2 Home Pos
G00X188 ; Enter Female Kinematic Mount Home Pos
A1 ; Latch on Kinematic Mount
G4 P5 ; Wait for Kinematic Mount to fully attach
G00X92 ; Exit Female Kinematic Mount Home Pos
#TODO X0.0Y0.0Z0.0 ;  ;Add tool offset coordinate
C2 ; Choosing tool 2 in the choose demultiplexer circuits

F600 ; setting default feedrate

S230 ; sets pwm speed when we enable it

G01 Z10F20 ; Moving Spindle to UP Postion

M3 ; Turn Motor ON
G4 P2 ; dwell for 2 seconds so motor reaches full RPM

G01 X84.504Y42.1736F600
G01 Z13F1
G01 Z10F20
G01 X92.124Y42.1736F600
G01 Z13F1
G01 Z10F20
G01 X72.7048Y27.7556F600
G01 Z13F1
G01 Z10F20
G01 X72.7048Y29.0256F600
G01 Z13F1
G01 Z10F20
G01 X72.7048Y30.2956F600
G01 Z13F1
G01 Z10F20
G01 X76.9808Y30.0924F600
G01 Z13F1
G01 Z10F20
G01 X76.9808Y22.4724F600
G01 Z13F1
G01 Z10F20
G01 X19.526Y30.2956F600
G01 Z13F1
G01 Z10F20
G01 X19.526Y27.7556F600
G01 Z13F1
G01 Z10F20
G01 X19.526Y25.2156F600
G01 Z13F1
G01 Z10F20
G01 X111.3724Y29.5736F600
G01 Z13F1
G01 Z10F20
G01 X111.3724Y32.0736F600
G01 Z13F1
G01 Z10F20
G01 X87.1816Y25.1134F600
G01 Z13F1
G01 Z10F20
G01 X87.1816Y22.5734F600
G01 Z13F1
G01 Z10F20
G01 X79.5616Y22.5734F600
G01 Z13F1
G01 Z10F20
G01 X79.5616Y25.1134F600
G01 Z13F1
G01 Z10F20
G01 X95.8784Y29.686F600
G01 Z13F1
G01 Z10F20
G01 X95.8784Y32.186F600
G01 Z13F1
G01 Z10F20
G01 X92.124Y28.1928F600
G01 Z13F1
G01 Z10F20
G01 X84.504Y28.1928F600
G01 Z13F1
G01 Z10F20
G01 X114.522Y28.0604F600
G01 Z13F1
G01 Z10F20
G01 X122.142Y28.0604F600
G01 Z13F1
G01 Z10F20
G01 X87.1916Y19.4244F600
G01 Z13F1
G01 Z10F20
G01 X87.1916Y16.8844F600
G01 Z13F1
G01 Z10F20
G01 X79.5716Y16.8844F600
G01 Z13F1
G01 Z10F20
G01 X79.5716Y19.4244F600
G01 Z13F1
G01 Z10F20
G01 X118.1288Y16.0208F600
G01 Z13F1
G01 Z10F20
G01 X115.5888Y16.0208F600
G01 Z13F1
G01 Z10F20
G01 X113.0488Y16.0208F600
G01 Z13F1
G01 Z10F20
G01 X50.9204Y14.7F600
G01 Z13F1
G01 Z10F20
G01 X22.9804Y14.7F600
G01 Z13F1
G01 Z10F20
G01 X122.1928Y33.5468F600
G01 Z13F1
G01 Z10F20
G01 X114.5728Y33.5468F600
G01 Z13F1
G01 Z10F20
G01 X35.9852Y30.2956F600
G01 Z13F1
G01 Z10F20
G01 X35.9852Y27.7556F600
G01 Z13F1
G01 Z10F20
G01 X35.9852Y25.2156F600
G01 Z13F1
G01 Z10F20
G01 X92.124Y36.6872F600
G01 Z13F1
G01 Z10F20
G01 X84.504Y36.6872F600
G01 Z13F1
G01 Z10F20
G01 X72.7048Y16.7828F600
G01 Z13F1
G01 Z10F20
G01 X72.7048Y18.0528F600
G01 Z13F1
G01 Z10F20
G01 X72.7048Y19.3228F600
G01 Z13F1
G01 Z10F20
G01 X73.4248Y13.8364F600
G01 Z13F1
G01 Z10F20
G01 X73.4248Y12.5664F600
G01 Z13F1
G01 Z10F20
G01 X73.4248Y11.2964F600
G01 Z13F1
G01 Z10F20
G01 X68.7512Y30.3972F600
G01 Z13F1
G01 Z10F20
G01 X68.7512Y27.8572F600
G01 Z13F1
G01 Z10F20
G01 X68.7512Y25.3172F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y37.2044F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y34.6644F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y32.1244F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y29.5844F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y27.0444F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y24.5044F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y21.9644F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y19.4244F600
G01 Z13F1
G01 Z10F20
G01 X107.156Y16.8844F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y16.8844F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y19.4244F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y21.9644F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y24.5044F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y27.0444F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y29.5844F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y32.1244F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y34.6644F600
G01 Z13F1
G01 Z10F20
G01 X99.536Y37.2044F600
G01 Z13F1
G01 Z10F20
G01 X54.2514Y11.9568F600
G01 Z13F1
G01 Z10F20
G01 X54.2514Y14.4968F600
G01 Z13F1
G01 Z10F20
G01 X54.2514Y17.0368F600
G01 Z13F1
G01 Z10F20
G01 X101.1108Y40.9636F600
G01 Z13F1
G01 Z10F20
G01 X103.6108Y40.9636F600
G01 Z13F1
G01 Z10F20
G01 X84.504Y33.6792F600
G01 Z13F1
G01 Z10F20
G01 X92.124Y33.6792F600
G01 Z13F1
G01 Z10F20
G01 X89.376Y25.1592F600
G01 Z13F1
G01 Z10F20
G01 X96.996Y25.1592F600
G01 Z13F1
G01 Z10F20
G01 X12.5664Y38.6268F600
G01 Z13F1
G01 Z10F20
G01 X7.4864Y38.6268F600
G01 Z13F1
G01 Z10F20
G01 X95.8832Y38.2004F600
G01 Z13F1
G01 Z10F20
G01 X95.8832Y40.7004F600
G01 Z13F1
G01 Z10F20
G01 X15.6652Y14.5476F600
G01 Z13F1
G01 Z10F20
G01 X10.5852Y14.5476F600
G01 Z13F1
G01 Z10F20
G01 X103.346Y7.588F600
G01 Z13F1
G01 Z10F20
G01 X95.726Y7.588F600
G01 Z13F1
G01 Z10F20
G01 X73.4248Y24.8092F600
G01 Z13F1
G01 Z10F20
G01 X73.4248Y23.5392F600
G01 Z13F1
G01 Z10F20
G01 X73.4248Y22.2692F600
G01 Z13F1
G01 Z10F20
G01 X52.3936Y30.3464F600
G01 Z13F1
G01 Z10F20
G01 X52.3936Y27.8064F600
G01 Z13F1
G01 Z10F20
G01 X52.3936Y25.2664F600
G01 Z13F1
G01 Z10F20
G01 X76.9808Y11.906F600
G01 Z13F1
G01 Z10F20
G01 X76.9808Y19.526F600
G01 Z13F1
G01 Z10F20
G01 X89.376Y19.5204F600
G01 Z13F1
G01 Z10F20
G01 X96.996Y19.5204F600
G01 Z13F1
G01 Z10F20
G01 X18.0528Y38.6268F600
G01 Z13F1
G01 Z10F20
G01 X23.1328Y38.6268F600
G01 Z13F1
G01 Z10F20
G01 X121.1768Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X118.6368Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X116.0968Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X113.5568Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X111.0168Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X108.4768Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X105.9368Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X103.3968Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X100.8568Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X98.3168Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X95.7768Y11.5504F600
G01 Z13F1
G01 Z10F20
G01 X93.2368Y11.5504F600
G01 Z13F1
G01 Z10F20

M5 ; disabling spindle PWM

; Returning the Deactivating Tool-2
C0 ; PWM Tool select demultiplexer to select tool zero which is the empty tool slot in multiplexers
#TODO X-0.0Y-0.0Z-0.0 ;  ;Remove tool offset coordinate
G00X165.0Y91.0Z12.0 ; Go to Tool-2 Home Pos
G00X92 ; Enter Female Kinematic Mount Home Pos
A0 ; Latch OFF Kinematic Mount
G4 P5 ; Wait for Kinematic Mount to fully detach
G00X188 ; Exit Female Kinematic Mount Home Pos

; Machine deinitialization Sequence... 
G00X0.0Y0.0Z0.0
B0 ; Turn Machine OFF