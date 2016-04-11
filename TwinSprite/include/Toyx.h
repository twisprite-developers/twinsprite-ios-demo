//
//  Toyx.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 23/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

/*! Toyx code version */
typedef NS_ENUM(NSInteger, ToyxCodeVersion) {
    
    /*! Unknow version */
    ToyxUnknowCodeVersion               = 0,
    ToyxCodeVersion1                    = 1,
    ToyxCodeVersion2                    = 2
};

@class ToyxSnapshot;

/*!
 It is a local representation of a Toyx object stored in the Twinsprite servers. The basic workflow for accessing existing toyx data is: instantiate a new toyx using his toyxId, create a device session for it if it doesn't exists, and use the different available fetching functions for retrieve the toyx data.
 */
@interface Toyx : NSObject 


/*!
 Make an empty toyx with this toyxId.
 @param toyxId Id for toy.
 @return Toyx instance.
 */
- (Toyx *) initWithToyxId: (NSString *) toyxId;

/*!
 Copy other toyx in this instance of toyx.
 @param toyxSource The toyx source.
 */
- (void) copyToyx: (Toyx *) toyxSource;

/*!
 Fill toyx with JSON data.
 @param data JSON data to fill toyx.
 @return Error or nill if there is not any error.
 */
- (NSError *) fromJSON: (NSData *) data;

/*!
 Get toyx attributes in JSON format.
 @return String with toyx serialized in JSON format.
 */
- (NSString *) getJSONAttributes;


#pragma mark CREATE SESSION FUNCTIONS

/*!
 Creates a device session for this toyx in actual device. Async Method.
 @param handler Invoked block when operation finishes.
 */
- (void) createSessionInBackground: (void (^)(NSError *error)) handler;



#pragma mark FETCH FUNCTIONS

/*!
 Fetches this toyx with the data from the server. Async Method.
 @param handler Invoked block when operation finishes.
 */
- (void) fetchInBackground: (void (^)(NSError *error)) handler;


/*!
 This method looks for this toyx in the local cache. If the toyx is not cached fetches this toyx with the data from the server. Async Method.
 @param handler Invoked block when operation finishes.
 */
- (void) fetchIfNeededInBackground: (void (^)(NSError *error)) handler;



#pragma mark SAVE FUNCTIONS

/*!
 Saves this toyx to the server. 
 @param handler Invoked block when operation finishes.
 */
- (void) save: (void (^)(NSError *error)) handler;

/*!
 Saves this toyx to the server. Async Method.
 @param handler Invoked block when operation finishes.
 */
- (void) saveInBackground: (void (^)(NSError *error)) handler;


/*!
 Saves this toyx to the server at some unspecified time in the future, even if Twinsprite is currently inaccessible. Use this when you may not have a solid network connection, and don't need to know when the save completes. If there is some problem with the toyx such that it can't be saved, it will be silently discarded. Toyx saved with this method will be stored locally in an cache until they can be delivered to Twinsprite. They will be sent in a maximum period of Twinsprite.CACHE_SYNC_INTERVAR milliseconds if possible. Otherwise, they will be sent the next time a network connection is available. Toyx saved this way will persist even after the app is closed, in which case they will be sent the next time the app is opened.
 @param handler Invoked block when operation finishes.
 */
- (void) saveEventually: (void (^)(NSError *error)) handler;



#pragma mark ATTRIBUTES MANAGE FUNCTIONS


/*!
 * Get the toyx identification
 * @return The toyx identification
 */
- (NSString *) getToyxId;

/*!
 Gets whether the toyx has been fetched.
 @return If the toyx has been fetched. False otherwise.
 */
- (bool) isDataAvaiable;

/*!
 Whether any attribute value in this toyx has been updated and not saved yet.
 @return Returns whether this toyx attributes has been altered and not saved yet.
 */
- (bool) isDirty;

/*!
 Whether any attribute value in this toyx has been updated and not saved yet.
 @param error If there are any error in the process.
 @return Returns whether this toyx attributes has been altered and not saved yet.
 */
- (bool) isDirty: (NSError **) error;


/*!
 Get the Toyx Snapshot
 @return The Toyx Snapshot
 */
- (ToyxSnapshot *) getToyxSnapshot;


/*!
 Returns a list of the attributes contained in this toyx.
 @return Toyx attributes names list.
 */
- (NSArray *) getAttrNames;


/*!
 Returns a list of the attributes contained in this toyx.
 @param error If there are any error in the process.
 @return Toyx attributes names list.
 */
- (NSArray *) getAttrNames: (NSError **) error;


/*!
 Whether this toyx has a particular attribute.
 @param attrName The name of the attribute to check for.
 @return True if operation sucess, false otherwise.
 */
- (bool) containsAttr: (NSString *) attrName;

/*!
 Whether this toyx has a particular attribute.
 @param attrName The name of the attribute to check for.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) containsAttr: (NSString *) attrName error: (NSError **) error;


/*!
 Whether this toyx has a particular attribute.
 @param attrName The name of the attribute to check for.
 @return True if operation sucess, false otherwise.
 */
- (bool) has: (NSString *) attrName;

/*!
 Whether this toyx has a particular attribute.
 @param attrName The name of the attribute to check for.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) has: (NSString *) attrName error: (NSError **) error;



#pragma mark GETTERS & SETTERS STRING FUNCIONS

/*!
 Access a NSString value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a string.
 */
- (NSString *) getString: (NSString *) attrName;

/*!
 Access a NSString value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a string.
 */
- (NSString *) getString: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as string.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putString: (NSString *) attrName value: (NSString *) value;

/*!
 Sets an attribute value as string.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putString: (NSString *) attrName value: (NSString *) value error: (NSError **) error;



#pragma mark GETTERS & SETTERS BOOLEAN FUNCIONS


/*!
 Access a bool value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a bool.
 */
- (bool) getBool: (NSString *) attrName;

/*!
 Access a bool value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a bool.
 */
- (bool) getBool: (NSString *) attrName error: (NSError **) error;

/*!
  Sets an attribute value as boolean.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putBool: (NSString *) attrName value: (bool) value;

/*!
 Sets an attribute value as boolean.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putBool: (NSString *) attrName value: (bool) value error: (NSError **) error;



#pragma mark GETTERS & SETTERS INTEGER FUNCIONS


/*!
 Access a int value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a int.
 */
- (int) getInt: (NSString *) attrName;

/*!
 Access a int value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a int.
 */
- (int) getInt: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as integer.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putInt: (NSString *) attrName value: (int) value;

/*!
 Sets an attribute value as integer.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putInt: (NSString *) attrName value: (int) value error: (NSError **) error;



#pragma mark GETTERS & SETTERS LONG FUNCIONS


/*!
 Access a long value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a long.
 */
- (long) getLong: (NSString *) attrName;

/*!
 Access a long value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a long.
 */
- (long) getLong: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as long.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putLong: (NSString *) attrName value: (long) value;

/*!
 Sets an attribute value as long.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putLong: (NSString *) attrName value: (long) value error: (NSError **) error;



#pragma mark GETTERS & SETTERS DOUBLE FUNCIONS


/*!
 Access a double value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a double.
 */
- (double) getDouble: (NSString *) attrName;

/*!
 Access a double value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a double.
 */
- (double) getDouble: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as double.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putDouble: (NSString *) attrName value: (double) value;

/*!
 Sets an attribute value as double.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putDouble: (NSString *) attrName value: (double) value error: (NSError **) error;



#pragma mark GETTERS & SETTERS FLOAT FUNCIONS


/*!
 Access a float value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a float.
 */
- (float) getFloat: (NSString *) attrName;

/*!
 Access a float value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a float.
 */
- (float) getFloat: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as float.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putFloat: (NSString *) attrName value: (float) value;

/*!
 Sets an attribute value as float.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putFloat: (NSString *) attrName value: (float) value error: (NSError **) error;



#pragma mark GETTERS & SETTERS DATE FUNCIONS


/*!
 Access a NSDate value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a NSDate.
 */
- (NSDate *) getDate: (NSString *) attrName;

/*!
 Access a NSDate value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a NSDate.
 */
- (NSDate *) getDate: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as date.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putDate: (NSString *) attrName value: (NSDate *) value;

/*!
 Sets an attribute value as date.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putDate: (NSString *) attrName value: (NSDate *) value error: (NSError **) error;


#pragma mark GETTERS & SETTERS DATA FUNCIONS


/*!
 Access a NSData value.
 @param attrName The attribute name to access the value for.
 @return The attribute if exists and is a NSData.
 */
- (NSData *) getData: (NSString *) attrName;

/*!
 Access a NSData value.
 @param attrName The attribute name to access the value for.
 @param error If there are any error in the process.
 @return The attribute if exists and is a NSData.
 */
- (NSData *) getData: (NSString *) attrName error: (NSError **) error;

/*!
 Sets an attribute value as data.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @return True if operation sucess, false otherwise.
 */
- (bool) putData: (NSString *) attrName value: (NSData *) value;

/*!
 Sets an attribute value as data.
 @param attrName The attribute name to set the value for.
 @param value new value for attribute.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) putData: (NSString *) attrName value: (NSData *) value error: (NSError **) error;


#pragma mark GETTERS & SETTERS INCREMENT FUNCIONS


/*!
 Automatically increments the given attribute by 1.
 @param attrName The attribute to increment.
 @return True if operation sucess, false otherwise.
 */
- (bool) incrementAttr: (NSString *) attrName;

/*!
 Automatically increments the given attribute by 1.
 @param attrName The attribute to increment.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) incrementAttr: (NSString *) attrName error: (NSError **) error;

/*!
 Automatically increments the given attribute by the given number.
 @param attrName The attribute to increment.
 @param increment The increment.
 @return True if operation sucess, false otherwise.
 */
- (bool) incrementAttr: (NSString *) attrName increment: (NSNumber *) increment;

/*!
 Automatically increments the given attribute by the given number.
 @param attrName The attribute to increment.
 @param increment The increment.
 @param error If there are any error in the process.
 @return True if operation sucess, false otherwise.
 */
- (bool) incrementAttr: (NSString *) attrName increment: (NSNumber *) increment error: (NSError **) error;



#pragma mark OTHER FUNCTIONS

/*!
 This method looks for this toyx in the local cache.
 @param toyxId Id of toyx.
 @return Toyx if toyx is in cache or nil in otherwise.
 */
+ (Toyx *) getFromCache: (NSString *) toyxId;

/*!
 * Gets the code version of toyx.
 * @param toyxId Id of toyx.
 * @return code version for this toyxId
 */
+ (ToyxCodeVersion) getCodeVersion: (NSString *) toyxId;

/*!
 * Gets the type id of toyx.
 * @param toyxId Id of toyx.
 * @return type id if toyx's version is greater than 1, 0 otherwise
 */
+ (int) getTypeId: (NSString *) toyxId;

/*!
 * Gets the customer id of toyx.
 * @param toyxId Id of toyx.
 * @return custoemr id if toyx's version is greater than 1, 0 otherwise
 */
+ (int) getCustomerId: (NSString *) toyxId;

@end
