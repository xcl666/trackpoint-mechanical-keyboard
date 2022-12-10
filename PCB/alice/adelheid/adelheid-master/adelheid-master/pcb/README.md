# 𝕬𝖉𝖊𝖑𝖍𝖊𝖎𝖉 - PCB

![adelheid_pcb_top](https://gist.githubusercontent.com/floookay/7bf6511a8d84804d32de4d7bbe3bd0fb/raw/4545813142abf2e65902b7caca10f7a3b39ebaed/rev1_assembled_top.jpg)  
![adelheid_pcb_bottom](https://gist.githubusercontent.com/floookay/7bf6511a8d84804d32de4d7bbe3bd0fb/raw/4545813142abf2e65902b7caca10f7a3b39ebaed/rev1_assembled_bottom.jpg)

The PCB for the Adelheid was designed using KiCAD on top of the Arisu PCB files.

## Changes compared to the Arisu PCB

- [x] Added a spaced function row
- [x] Added footprint for stepped caps lock key
- [x] Changed the micro USB port to a tht mini USB port
- [x] Added single color underglow and key lighting

## FateNozomi's Arisu description

>アリス PCB designed using KiCad. The layout is inspired by Lyn's EM7 and TGR Alice with some modification of my own.
>
> Key differences:
>
> - I removed the extra [B] key on the right half and shifted the [NM,.?] row > to the left by 0.25U.
> - Shifted the 3 keys to the right and added arrow keys.
> - Tweaked the bottom so that the 1.5U keys doesn't protrude out a little.
>
> Shifting the [NM,.?] row to the left by 0.25U required quite some work on the arrangement of keys for the right half.  
> As a result, this does not give the same typing experience as Lyn's EM7 and TGR Alice.
> Lyn's EM7 and TGR Alice uses the home row as the center point to vertically align both halves while I used the number row instead.  
> Due to the nature of staggered keyboards, aligning using the number row resulted in the home row not being aligned.

The Adelheid inherits these changes from the Arisu.

## KiCAD libraries in use

- [ai03/MX_Only](https://github.com/ai03-2725/MX_Alps_Hybrid/tree/master/MX_Only.pretty) for MX switch footprints (local copy in `./lib/`)
- [Keebio-Parts](https://github.com/keebio/Keebio-Parts.pretty) for mini USB port footprint

## Parts list

### SMD

All SMD parts are listed in the [BOM](./adelheid.gerber/adelheid.csv) with their corresponding value, label and LCSC number.  
If you opt in for LED backlighting/underglow please make sure to use the correct resistor size for your LEDs in order for your PCB to function correctly. See [here](#backlighting) for led resistor estimations.

### THT

- 82x MX switches
- 1x through-hole mini USB 2.0 port (MX-54819-0519)
- (optional) 82x 3mm single color LEDs

## Backlighting

To calculate what resistors you'll need you can use my [backlight calculator spreadsheet](./backlight.ods) to calculate the estimated total power draw. Enter your LED specifications and either enter the desired current per LED or enter the resistor size which you are planning on using. The spreadsheet should calculate the total power draw and compare it to the allowed power draw of USB 2.0 (500 mA). *I'm no electrical engineer so please be cautious.*

<!-- ![underglow](https://gist.githubusercontent.com/floookay/7bf6511a8d84804d32de4d7bbe3bd0fb/raw/4545813142abf2e65902b7caca10f7a3b39ebaed/underglow.jpg) -->
<!-- ![full backlight](https://gist.githubusercontent.com/floookay/7bf6511a8d84804d32de4d7bbe3bd0fb/raw/9e10a12793ed65a09f529caf7a6c52b8ec96cc22/backlight_full.jpg) -->

## **Disclaimer**

Please use these files at your own risk.
