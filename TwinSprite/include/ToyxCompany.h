//
//  ToyxCompany.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 26/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CryptoCoding.h"

/*!
 ToyxCompany contains basic information about the owner company of a fetched Toyx.
 */
@interface ToyxCompany : NSObject <CryptoCoding>

/*!
 Fill the ToyxCompany with dictionary data.
 @param dictionary Dictionary with de ToyxCompany data.
 @return NSError or nil if there is not any error.
 */
- (NSError *) fromDictionary: (NSDictionary *) dictionary;

/*!
 Get the company name.
 @return The company name.
 */
- (NSString *) getName;

/*!
 Get the company description.
 @return Company description.
 */
- (NSString *) getDescription;


@end
