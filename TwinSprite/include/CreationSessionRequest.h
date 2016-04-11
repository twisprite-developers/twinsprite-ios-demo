//
//  CreationSessionRequest.h
//  TwinSpriteSDK
//
//  Created by Alfredo Villarino on 12/2/16.
//  Copyright © 2016 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Toyx;

@interface CreationSessionRequest : NSObject

/*!
 Creates a device session for this toyx in actual device. Async Method.
 @param toyxId Id of toyx.
 @param handler Invoked block when operation finishes.
 */
+ (void) createSessionInBackground: (NSString *) toyxId
                       andCallback: (void (^)(Toyx *toyx, NSError *error)) handler;

@end
