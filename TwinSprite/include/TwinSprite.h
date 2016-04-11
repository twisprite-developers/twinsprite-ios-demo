//
//  TwinSprite.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 23/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TwinSpriteContext.h"


/*! Error types */
typedef NS_ENUM(NSInteger, TwinSpriteErrorCode) {
    
    /*! No error */
  	TwinSpriteNoError                   = 0,
    
    // Server side errors
    
    /*! General server error */
	TwinSpriteServerError               = 1,
    /*! Authentication error */
    TwinSpriteAuthenticationFailure     = 2,
    /*! Toyx not found error */
    TwinSpriteToyxNotFound              = 3,
    /*! Invalid toyx error */
    TwinSpriteInvalidToyxId             = 4,
    /*! Invalid Api Key error */
    TwinSpriteInvalidApiKey             = 5,
    /*! Model not avaiable error */
    TwinSpriteModelNotAvaiable          = 6,
    /*! Unomdificable attribute error */
    TwinSpriteUnmodificableAttrUpdate   = 7,
    /*! Max request per toyx error */
    TwinSpriteMaxReqPerToyx             = 8,
    /*! No device session error */
    TwinSpriteNoDeviceSession           = 9,
    /*! Max devices per toyx error */
    TwinSpriteMaxDevicesPerToyx         = 10,
    
    // Client side errors
     
    /*! Time out error*/
    TwinSpriteTimeout                   = 11,
    /*! Network error*/
    TwinSpriteNetworkError              = 12,
    
    
    // Internal errors
    
    /*! Parser error */
    TwinSpriteParserError               = 13,
    /*! No data avaiable error */
    TwinSpriteNoDataAvaiable            = 14,
    /*! Attribute not found error */
    TwinSpriteAttrNotFound              = 15,
    /*! Cast attribute error */
    TwinSpriteAttrCastError             = 16,
    /*! Cache error */
    TwinSpriteCacheError            = 17

};

/*!
 The Twinsprite class contains static functions that handle global configuration for the Twinsprite library.
 */
@interface TwinSprite : NSObject

/*!
 Authenticates this client as belonging to your application. This must be called before your application can use the Twinsprite library. The recommended way is to put a call to Twinsprite.initialize in each of your onCreate methods.
 @param apiKey The api key provided in the Twinsprite development portal.
 @param secretKey The secret key provided in the Twinsprite development portal.
 */
+ (void) initializeWithApiKey: (NSString *) apiKey andSecretKey: (NSString *) secretKey;

/*!
 Authenticates this client as belonging to your application. This must be called before your application can use the Twinsprite library. The recommended way is to put a call to Twinsprite.initialize in each of your onCreate methods.
 @param twinSpriteContext Execution context for Twinsprite.
 @param apiKey The api key provided in the Twinsprite development portal.
 @param secretKey The secret key provided in the Twinsprite development portal.
 */
+ (void) initializeWithContext: (TwinSpriteContext *) twinSpriteContext
                     andApiKey: (NSString *) apiKey
                  andSecretKey: (NSString *) secretKey;



/*! 
 Get api key
 @return The api key.
 */
+ (NSString *) apiKey;

/*! 
 Get secret key.
 @return The secret key.
 */
+ (NSString *) secretKey;

/*! 
 Get request time out connection.
 @return The request time out connection.
 */
+ (int) requestTimeOut;

/*! 
 Get cache sync interval in seconds.
 @return The cache sync interval.
 */
+ (int) cacheSyncInterval;

/*! 
 Get max cache size in bytes.
 @return The max caches size in bytes.
 */
+ (long long) maxCacheSizeBytes;

/*! 
 Get max cache live time in seconds
 @return The max cache live time.
 */
+ (int) maxCacheLiveTime;

/*! 
 Set log level used by sdk.
 @param logLevel The log level used by sdk.
 */
+ (void) setLogLevel: (TwinSpriteLogLevel) logLevel;

/*!
 Get log level used by sdk.
 @return The log level used.
 */
+ (TwinSpriteLogLevel) getLogLevel;


@end
