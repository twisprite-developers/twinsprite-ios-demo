# Twinsprite iOS SDK Demo

This repository includes an Xcode Objective-C project with a demo APP that illustrates the main Twinsprite SDK methods. The Twinsprite iOS SDK library (libSDK.a) and the include directory with the required interface files are included in the project.

The project also illustrates how to extract a ToyxID from a QR code using a basic QR scanner.

## Setup

1. If you don't have a [Twinsprite Development Portal](http://devportal.twinsprite.com/) account, follow the [Quick Start Guide](http://developers.twinsprite.com/v2/docs/pages/quickstart.html) to create an account, a game and some development Toyx.

2. Open the Xcode project and replace the <b>API_KEY</b> and <b>SECRET_KEY</b> strings at the top of [MainViewController.m](https://github.com/twisprite-developers/twinsprite-ios-sdk/blob/master/TwinSprite/MainViewController.m) with your game key-pair.

3. Build the application and run it on an iOS device. Acan a valid toyxID QR code from the [Twinsprite Development Portal](http://devportal.twinsprite.com/) and start making requests.

![image](http://developers.twinsprite.com/images/ios-demo-app.png)


## Code Overview

* [MainViewController.m](https://github.com/twisprite-developers/twinsprite-ios-sdk/blob/master/TwinSprite/MainViewController.m) provides code examples of how to create a session, retrieve and update the Toyx data.

* [ScanViewController.m](https://github.com/twisprite-developers/twinsprite-ios-sdk/blob/master/TwinSprite/ScanViewController.m) illustrates how to implement a basic QR scanner exploiting the iOS SDK capabilities.


## Resources

[Twinsprite iOS SDK Documentation Site](http://developers.twinsprite.com/v2/docs/pages/ios/quickstart.html)

[Twinsprite iOS SDK Reference](http://developers.twinsprite.com/v2/sdk/ios/index.html)

[Twinsprite iOS SDK Module](http://developers.twinsprite.com/v2/downloads/ios/TwinspriteSDK.zip)



Support: [dev@twinsprite.com](mailto:dev@twinsprite.com)
