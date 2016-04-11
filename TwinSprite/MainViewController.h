//
//  MainViewController.h
//  TwinSprite
//
//  Created by Alfredo on 15/01/14.
//  Copyright (c) 2014 Carbonbyte. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Toyx;

@interface MainViewController : UIViewController <UITextFieldDelegate>{
    Toyx *toyx;
}

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *spinner;
@property (weak, nonatomic) IBOutlet UITextField *textFieldCode;

- (IBAction)clickCreateSession;
- (IBAction)clickFetch;
- (IBAction)clickSave;

@end
