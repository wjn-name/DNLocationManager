//
//  DNLocationManager.h
//  DNLocationManager
//
//  Created by mainone on 16/9/13.
//  Copyright © 2016年 wjn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

typedef void (^DNLocationBlock)(CLLocationCoordinate2D locationCorrrdinate);
typedef void (^DNAddressBlock)(NSString *addressString);
typedef void (^DNCityBlock)(NSString *cityString);
typedef void (^DNLocationErrorBlock) (NSError *error);
typedef void (^DNAddressErrorBlock) (NSError *error);

@interface DNLocationManager : NSObject

+ (DNLocationManager *)shareLocation;

/**
 *  获取坐标
 *
 *  @param locaiontBlock 坐标详情
 */
- (void)getLocationCoordinate:(DNLocationBlock)locaiontBlock failure:(DNLocationErrorBlock)error;

/**
 *  获取详细地址
 *
 *  @param addressBlock 详细地址
 */
- (void)getAddress:(DNAddressBlock)addressBlock failure:(DNAddressErrorBlock)error;

/**
 *  获取坐标和详细地址
 *
 *  @param locaiontBlock 坐标详情
 *  @param addressBlock  详细地址
 */
- (void)getLocationCoordinate:(DNLocationBlock)locaiontBlock withAddress:(DNAddressBlock)addressBlock failure:(DNLocationErrorBlock)error addressFailure:(DNAddressErrorBlock)Aerror;

/**
 *  获取城市名
 *
 *  @param cityBlock 城市名
 */
- (void)getCity:(DNCityBlock)cityBlock failure:(DNAddressErrorBlock)error;

@end
