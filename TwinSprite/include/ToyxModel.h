//
//  ToyxModel.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 24/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TwinSpriteError.h"
#import "CryptoCoding.h"

@class ToyxCompany;

/*!
 Represents the model of a fetched toyx.
 */
@interface ToyxModel : NSObject <CryptoCoding>

/*!
 Fill the model with dictionary data.
 @param dictionary Dictionary with de model data.
 @return NSError or nil if there is not any error.
 */
- (NSError *) fromDictionary: (NSDictionary *) dictionary;


/*!
 Get the model id.
 @return The model id.
 */
- (long) getId;


/*!
 Get the model creation time.
 @return The model creation time.
 */
- (NSDate *) getCreationTime;


/*!
 Get the model description.
 @return The model description.
 */
- (NSString *) getDescription;

/*!
 Get the model name.
 @return The model name.
 */
- (NSString *) getName;


/*!
 Get the model ToyxCompany.
 @return The model ToyxCompany.
 */
- (ToyxCompany *) getCompany;

@end
