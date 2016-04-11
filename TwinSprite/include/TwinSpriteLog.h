//
//  TwinSpriteLog.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 30/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 La clase TwinSpriteLog es la encargada de mostrar en consola los mensajes atendiendo al nivel de Log requerido por el usuario.
 */
@interface TwinSpriteLog : NSObject

/*!
 Función que muestra en consola los mensajes con un nivel menor o igual a TwinSpriteErrorLog
 @param message El mensaje que saldrá por consola.
 */
+ (void) error: (NSString *) message;

/*!
 Función que muestra en consola los mensajes con un nivel menor o igual a TwinSpriteErrorLog
 @param message El mensaje que saldrá por consola.
 */
+ (void) errorFormated: (NSString *) message, ... NS_FORMAT_FUNCTION(1,2);

/*!
 Función que muestra en consola los mensajes con un nivel menor o igual a TwinSpriteInfoLog
 @param message El mensaje que saldrá por consola.
 */
+ (void) info: (NSString *) message;

/*!
 Función que muestra en consola los mensajes con un nivel menor o igual a TwinSpriteInfoLog
 @param message El mensaje que saldrá por consola. 
 */
+ (void) infoFormated: (NSString *) message, ... NS_FORMAT_FUNCTION(1,2);

@end
