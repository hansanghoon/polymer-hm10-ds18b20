# \<hm10thermo-app\>

Connect to HM-10 BLE(Bluetooth Low Energe) module with DS18B20 1-wire digital thermometer using Polymer and Web Bluetooth technology.

Tested with HM-10 copycat CS2541 module from bolutek.

## Pin configuration

Arduino Uno

|arduino|HM-10|DS18B20|note|
|----|----|----|----|
|5V or 3.3V|VCC|VCC|both 5/3.3V works|
|Pin 8|TXD|||
|Pin 7|RXD|||
|Pin 5||Bus|4.7k pull-up register|


## Install the Polymer-CLI

First, make sure you have the [Polymer CLI](https://www.npmjs.com/package/polymer-cli) installed. Then run `polymer serve` to serve your application locally.

## Viewing Your Application

To use firebase funcionalities, install [Firebase CLI](https://github.com/firebase/firebase-tools). 

```
$ polymer serve
$ firebase serve
```

## Firebase App

Visit [https://polymer-hm10-ds18b20.firebaseapp.com/](https://polymer-hm10-ds18b20.firebaseapp.com/)

## Building Your Application

```
$ polymer build
```

This will create a `build/` folder with `bundled/` and `unbundled/` sub-folders
containing a bundled (Vulcanized) and unbundled builds, both run through HTML,
CSS, and JS optimizers.

You can serve the built versions by giving `polymer serve` a folder to serve
from.

```
$ polymer serve build/bundled
```