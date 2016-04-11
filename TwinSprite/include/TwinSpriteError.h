//
//  TwinSpriteError.h
//  prueba-oauth-request
//
//  Created by Carbonbyte on 24/12/13.
//  Copyright (c) 2013 Carbonbyte. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 La clase TwinSpriteError proporciona una serie de métodos para crear errores que utilizarán las funciones del SDK.
 */
@interface TwinSpriteError : NSObject

/*!
 Función que crea un error con un código y un mensaje pasados como parámetro.
 @param errorCode Código de error dentro de la enumaración TwinSpriteErrorCode.
 @param message Mensaje para describir el error.
 @return El error creado.
 */
+ (NSError *) createWithErrorCode: (int) errorCode andMessage: (NSString *) message;

/*!
 Función que crea un error de acuerdo a la respuesta de una request en el servidor. 
 @param responseData Datos del error generado por el servidor. Será desparseado para averiguar el código de error y el mensaje del mismo.
 @return El error creado.
 */
+ (NSError *) createWithResponseData: (NSData *) responseData;


@end
