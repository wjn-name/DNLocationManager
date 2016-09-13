# DNLocationManager
手机定位功能


###必要配置

1)添加依赖库

    CoreLocation.framework

2)配置plist 注意：类型要选择String，ios8中类型选择boolean会出现设置界面崩溃的情况）

    NSLocationAlwaysUsageDescription String YES
    NSLocationWhenInUseUsageDescription String YES

#使用说明
1.引入头文件#import "DNLocationManager.h"

2.调用相应的方法获取对应信息

获取坐标
      
    - (void)getLocation {
        [[DNLocationManager shareLocation] getLocationCoordinate:^(CLLocationCoordinate2D locationCorrrdinate) {
           NSLog(@"经度:%f  纬度:%f",locationCorrrdinate.latitude, locationCorrrdinate.longitude);
       } failure:^(NSError *error) {
           NSLog(@"获取坐标失败:%@",error);
        }];
    }


获取地址
    
    - (void)getAddress {
        [[DNLocationManager shareLocation] getAddress:^(NSString *addressString) {
            NSLog(@"获取到的地址:%@",addressString);
        } failure:^(NSError *error) {
            NSLog(@"获取地址失败:%@",error);
        }];
    }


获取坐标和地址
    
    - (void)getLocationAndAddress {
       [[DNLocationManager shareLocation] getLocationCoordinate:^(CLLocationCoordinate2D locationCorrrdinate) {
            NSLog(@"经度:%f  纬度:%f",locationCorrrdinate.latitude, locationCorrrdinate.longitude);
        } withAddress:^(NSString *addressString) {
            NSLog(@"获取到的地址:%@",addressString);
       } failure:^(NSError *error) {
            NSLog(@"获取坐标失败:%@",error);
        } addressFailure:^(NSError *error) {
            NSLog(@"获取地址失败:%@",error);
        }];
    }
    

 获取城市
    
    - (void)getCity {
        [[DNLocationManager shareLocation] getCity:^(NSString *cityString) {
            NSLog(@"城市名称:%@",cityString);
        } failure:^(NSError *error) {
            NSLog(@"获取城市失败:%@",error);
        }];
    }
