//
//  TwinSpriteContext.h
//  TwinSpriteSDK
//
//  Created by Alfredo Villarino on 12/2/16.
//  Copyright © 2016 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TwinSpriteContext : NSObject

/*! Levels log. */
typedef NS_ENUM(NSInteger, TwinSpriteLogLevel) {
    
    /*! No log */
    TwinSpriteNoLog     = 0,
    /*! Error log */
    TwinSpriteErrorLog  = 1,
    /*! Info log */
    TwinSpriteInfoLog   = 2
    
};

@property (nonatomic, assign, setter=setLogLevel:) TwinSpriteLogLevel logLevel;
@property (nonatomic, assign, setter=setMaxCacheLiveTime:) int maxCacheLiveTime;
@property (nonatomic, assign, setter=setMaxCacheSize:) long maxCacheSize;
@property (nonatomic, assign, setter=setCacheSyncInterval:) int cacheSyncInterval;
@property (nonatomic, assign, setter=setRequestTimeOut:) int requestTimeOut;





@end
