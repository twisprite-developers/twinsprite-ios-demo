//
//  ToyxQuery.h
//  TwinSpriteSDK
//
//  Created by Alfredo Villarino on 12/2/16.
//  Copyright © 2016 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Toyx;

@interface ToyxQuery : NSObject

/*!
 Gets this toyx with the data from the server. Async Method.
 @param toyxId Id of the toyx
 @param handler Invoked block when operation finishes.
 */
+ (void) getInBackground: (NSString *) toyxId
             andCallback: (void (^)(Toyx *toyx, NSError *error)) handler;

/*!
 This method looks for this toyx in the local cache. If the toyx is not cached fetches this toyx with the data from the server. Async Method.
 @param toyxId Id of the toyx
 @param handler Invoked block when operation finishes.
 */
+ (void) getIfNeededInBackground: (NSString *) toyxId
                     andCallback: (void (^)(Toyx *toyx, NSError *error)) handler;


@end
