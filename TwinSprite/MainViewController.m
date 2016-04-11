//
//  MainViewController.m
//  TwinSprite
//
//  Created by Alfredo on 15/01/14.
//  Copyright (c) 2014 Carbonbyte. All rights reserved.
//

#import "MainViewController.h"
#import "ScanViewController.h"
#import "TwinSprite.h"
#import "Toyx.h"
#import "TwinSpriteContext.h"
#import "CreationSessionRequest.h"
#import "ToyxQuery.h"


@implementation MainViewController


- (void)viewDidLoad {
    [super viewDidLoad];

    // Keys
    NSString *apiKey = @"API_KEY";
    NSString *secretKey = @"SECRET_KEY";
   
    
    // Create context
    TwinSpriteContext *twinSpriteContext = [[TwinSpriteContext alloc] init];
    twinSpriteContext.logLevel = TwinSpriteInfoLog;
    
    // Init twinsprite
   	[TwinSprite initializeWithContext: twinSpriteContext andApiKey: apiKey andSecretKey: secretKey];

}


- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear: animated];
    
    // Check if has new code
    NSString *code = [ScanViewController getCode];
    
      if (code) {
        self.textFieldCode.text = code;
    }
}


- (IBAction)clickCreateSession {
    
    // Check api key and secret key
    if ([[TwinSprite apiKey] isEqualToString: @"API_KEY"] || [[TwinSprite secretKey] isEqualToString: @"SECRET_KEY"]) {
        [self showAlert: @"Insert valid API_KEY and SECRET_KEY"];
        return;
    }
    
    // Check toyx id
    if (self.textFieldCode.text.length == 0) {
        [self showAlert: @"No Toyx Id"];
        return;
    }
    
    // Show spinner
    self.spinner.hidden = false;
    
    // Create session
    [CreationSessionRequest createSessionInBackground: self.textFieldCode.text andCallback:^(Toyx *newToyx, NSError *error) {
        
        if (error) {
            [self performSelectorOnMainThread: @selector(showAlert:) withObject: error.localizedDescription waitUntilDone: false];
        } else {
            [self performSelectorOnMainThread: @selector(showAlert:) withObject: @"Created session" waitUntilDone: false];
            toyx = newToyx;
        }
        
        // Hide spinner
        [self performSelectorOnMainThread: @selector(hideSpinner) withObject: nil  waitUntilDone: false];
        
    }];
   
    
}

- (IBAction) clickFetch {
    
    // Check toyx
    if (!toyx) {
        [self showAlert: @"No Toyx, create session before"];
        return;
    }
    
    // Show spinner
    self.spinner.hidden = false;
    
    // Get
    [ToyxQuery getInBackground: [toyx getToyxId] andCallback:^(Toyx *newToyx, NSError *error) {
        
        if (error) {
            [self performSelectorOnMainThread: @selector(showAlert:) withObject: error.localizedDescription waitUntilDone: false];
        } else {
            [self performSelectorOnMainThread: @selector(showAlert:)
                                   withObject: [NSString stringWithFormat: @"Feched:\n %@",toyx]
                                waitUntilDone: false];
            toyx = newToyx;
        }
        
        // Hide spinner
        [self performSelectorOnMainThread: @selector(hideSpinner) withObject: nil  waitUntilDone: false];
        
    }];
    
    
}

- (IBAction)clickSave {
    
    // Check toyx
    if (!toyx) {
        [self showAlert: @"No Toyx, create session before"];
        return;
    }
    
    // Show spinner
    self.spinner.hidden = false;
    
    // Save
    [toyx saveInBackground: ^(NSError *error) {
        if (error) {
            [self performSelectorOnMainThread: @selector(showAlert:) withObject: error.localizedDescription waitUntilDone: false];
        } else {
            [self performSelectorOnMainThread: @selector(showAlert:)
                                   withObject: [NSString stringWithFormat: @"Saved:\n %@",toyx]
                                waitUntilDone: false];
        }
        
        // Hide spinner
        [self performSelectorOnMainThread: @selector(hideSpinner) withObject: nil  waitUntilDone: false];
        
    }];
    
}




- (void) hideSpinner {
    self.spinner.hidden = true;
}

- (void) showAlert: (NSString *) message {
    UIAlertView *errorAlert = [[UIAlertView alloc] initWithTitle: @"Alert"
                                                         message: message
                                                        delegate:nil
                                               cancelButtonTitle:@"OK"
                                               otherButtonTitles:nil];
    [errorAlert show];
}


#pragma mark TEXT FIELD

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    [self.view endEditing:YES];
    [super touchesBegan:touches withEvent:event];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [self.view endEditing:YES];
    return  true;
}

@end
