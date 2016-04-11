//
//  ScanViewController.h
//  TwinSprite
//
//  Created by Alfredo on 15/01/14.
//  Copyright (c) 2014 Carbonbyte. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface ScanViewController : UIViewController <AVCaptureMetadataOutputObjectsDelegate>

@property(nonatomic, strong) AVCaptureSession *session;
@property(nonatomic, strong) UIView *previewView;
@property(nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;

@property (nonatomic, weak) IBOutlet UIView *previewContainer;

+ (NSString *) getCode;

@end
