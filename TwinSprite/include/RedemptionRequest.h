//
//  RedemptionRequest.h
//  TwinSpriteSDK
//
//  Created by Alfredo Villarino on 12/2/16.
//  Copyright © 2016 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Toyx;

@interface RedemptionRequest : NSObject

/*!
 Redeems a toyx code in server. Async Method.
 @param toyxId Id of toyx to redeem.
 @param handler Invoked block when operation finishes.
 */
+ (void) redeemInBackground: (NSString *) toyxId
                andCallback: (void (^)(Toyx *toyx, NSError *error)) handler;


@end
