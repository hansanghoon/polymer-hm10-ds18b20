# \<hm10thermo-app\>

Connect to HM-10 BLE(Bluetooth Low Energe) module with DS18B20 1-wire digital thermometer using Polymer and Web Bluetooth technology.

Tested with HM-10 copycat CS2541 module from bolutek.

## Install the Polymer-CLI

First, make sure you have the [Polymer CLI](https://www.npmjs.com/package/polymer-cli) installed. Then run `polymer serve` to serve your application locally.

## Viewing Your Application

```
$ polymer serve
```

### Firebase App

Visit [https://polymer-hm10-ds18b20.firebaseapp.com/](https://polymer-hm10-ds18b20.firebaseapp.com/)

## Building Your Application

```
$ polymer build
```

This will create a `build/` folder with `bundled/` and `unbundled/` sub-folders
containing a bundled (Vulcanized) and unbundled builds, both run through HTML,
CSS, and JS optimizers.

You can serve the built versions by giving `polymer serve` a folder to serve
from:

```
$ polymer serve build/bundled
```