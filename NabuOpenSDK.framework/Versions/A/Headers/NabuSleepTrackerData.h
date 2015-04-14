//
//  NabuSleepTrackerData.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/3/14.
//  Copyright (c) 2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuSleepTracker
 @abstract A class that defines a list of Nabu fitness data within a specified time
    @discussion
 
        @param  sleepDataArray   Array of NabuSleepTrackerData objects
        @param  sleepHistoryDataArray    Array of NabuSleepHistoryData objects
 */

@interface NabuSleepTracker : NSObject

@property (copy, nonatomic) NSMutableArray *sleepDataArray;
@property (copy, nonatomic) NSMutableArray *sleepHistoryDataArray;

@end

/*!
 @class NabuSleepTrackerData
 @abstract  A class that defines the Nabu Sleep Tracker Data
    @discussion
 
        @param  startTime  Start time of list of fitness data in Unix timestamp
        @param  endTime    End time of list of fitness data in Unix timestamp
        @param  sleepData  List of sleep data
 
 */

@interface NabuSleepTrackerData : NSObject

@property (nonatomic) NSString *bandId;
@property (nonatomic) NSString *modelName;

@property (nonatomic) double startTime;
@property (nonatomic) double endTime;

@property (nonatomic) NSString *sleepData;
@property (nonatomic) NSString *sleepDataInMinutes;


@end

/*!
 @class NabuSleepHistoryData
 @abstract  A class that defines the Nabu Sleep History Data
    @discussion
 
        @param bandId      Nabu Device ID
        @param modelName   Nabu Device Type
        @param sleepHistoryRecordDate  Timestamp of sleep data (start date of data)
        @param deepSleep   Deep sleep in minutes
        @param lightSleep  Light sleep in minutes
        @param sleepEfficiency  Sleep efficiency in a percentage
 */

@interface NabuSleepHistoryData : NSObject

@property (nonatomic) NSString *bandId;
@property (nonatomic) NSString *modelName;

@property (nonatomic) double numOfDays;

@property (nonatomic) double sleepHistoryRecordDate;
@property (nonatomic) NSString *efficiency DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. - use sleepEfficiency");
@property (nonatomic) NSString *good DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. - use deepSleep");
@property (nonatomic) NSString *bad DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. - use lightSleep");
@property (nonatomic) NSInteger deepSleep;
@property (nonatomic) NSInteger lightSleep;
@property (nonatomic) NSInteger sleepEfficiency;


@end
