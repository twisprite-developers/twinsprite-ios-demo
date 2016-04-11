//
//  ScanViewController.m
//  TwinSprite
//
//  Created by Alfredo on 15/01/14.
//  Copyright (c) 2014 Carbonbyte. All rights reserved.
//

#import "ScanViewController.h"



@implementation ScanViewController

static NSString *code = nil;

+ (NSString *) getCode {
    return code;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Set code to nil
    code = nil;
    
    // Create a session
    self.session = [[AVCaptureSession alloc] init];
	
    // Create a preview layer
    self.previewLayer = [AVCaptureVideoPreviewLayer layerWithSession:self.session];
    self.previewLayer.frame = self.previewContainer.bounds;
    self.previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    [self.previewContainer.layer addSublayer: self.previewLayer];
    
    
    
	// Get the Camera Device
    NSArray *devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
	AVCaptureDevice *camera = nil;
    for(camera in devices) {
        if(camera.position == AVCaptureDevicePositionBack) {
            break;
        }
    }
	
	// Create a AVCaptureInput with the camera device
	NSError *error=nil;
	AVCaptureDeviceInput *cameraInput = [[AVCaptureDeviceInput alloc] initWithDevice:camera error:&error];
	if (cameraInput == nil) {
		NSLog(@"Error to create camera capture:%@",error);
        return;
	}
    
 	// Add the input and output
	[self.session addInput:cameraInput];
    
    // Create a VideoDataOutput and add it to the session
    AVCaptureMetadataOutput *output = [[AVCaptureMetadataOutput alloc] init];
    [self.session addOutput:output];
    
    
    // Add QR type
    NSSet *potentialDataTypes = [NSSet setWithArray:@[AVMetadataObjectTypeQRCode]];
    
    NSMutableArray *supportedMetaDataTypes = [NSMutableArray array];
    for(NSString *availableMetadataObject in output.availableMetadataObjectTypes) {
        if([potentialDataTypes containsObject:availableMetadataObject]) {
            [supportedMetaDataTypes addObject:availableMetadataObject];
        }
    }
    
    [output setMetadataObjectTypes:supportedMetaDataTypes];
    
    // Get called back when something is recognised
    [output setMetadataObjectsDelegate:self queue:dispatch_get_main_queue()];
	
	// Start the session running
	[self.session startRunning];
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputMetadataObjects:(NSArray *)metadataObjects fromConnection:(AVCaptureConnection *)connection {
    
    
    for(AVMetadataMachineReadableCodeObject *recognizedObject in metadataObjects) {
       
        NSLog(@"%@", recognizedObject.stringValue);
        
        // Stop session
        [self.session stopRunning];
        
        // Save code
        code = recognizedObject.stringValue;
        
        // Go back
        [self.navigationController popViewControllerAnimated: true];
    }
    
}


@end
