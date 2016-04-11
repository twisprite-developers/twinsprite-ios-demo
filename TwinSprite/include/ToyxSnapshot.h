//
//  ToyxSnapshot.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 24/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CryptoCoding.h"

@class ToyxModel;

/*!
 Describes the active model snapshots of a fetched toyx.
 */
@interface ToyxSnapshot : NSObject <CryptoCoding>

/*!
 Fill the toyx snapshot with dictionary data.
 @param dictionary Dictionary with de toyx snapshot data.
 @return NSError or nil if there is not any error.
 */
- (NSError *) fromDictionary: (NSDictionary *) dictionary;


/*!
 Get the toyx snapshot enviroment.
 @return The toyx snapshot enviroment.
 */
- (NSString *) getEnviroment;

/*! 
 Get the toyx snapshot time.
 @return The toyx snapshot time.
 */
- (NSDate *) getTime;

/*!
 Get the ToyxModel of toyx snapshot.
 @return The ToyxModel of toyx snapshot.
 */
- (ToyxModel *) getToyxModel;

@end
