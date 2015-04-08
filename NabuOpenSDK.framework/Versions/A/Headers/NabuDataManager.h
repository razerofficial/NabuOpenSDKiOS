//
//  NabuDataManager.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/3/14.
//  Copyright(c)2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NabuOpenSDKConstants.h"

/*!Generic Nabu Completion Block. 
 *
 * @deprecated SDK No longer supports generic completion blocks.
 */
typedef void(^NabuCompletionBlock)(NSDictionary *)DEPRECATED_MSG_ATTRIBUTE("No longer supported. Will be removed in future release.");

@class NabuNotification, NabuUserProfile;


/**
 *  Class that defines the Nabu Data Manager
 */
@interface NabuDataManager : NSObject



/**
*  This is a singleton instance of the Nabu Data Manager
*
*  @return sharedDataManager
*  @see NabuDataManager
*/
+(id)sharedDataManager;



/**
 *  This method will construct a URL using the formatted information from client app Id, scope and URL scheme callback.
 *
 *  @param appId          Your client's App Id - This is your App Key from Nabu Developer Portal.
 *  @param appScope       Your client's Scope upon registration
 *  @param appURICallback Your client's custom defined URL scheme for app to app communication. Must be the root scheme and not like this format(i.e., RZOrg://page=1)
 *
 *  @return A constructed URL formed data that will be called to request authorization in order to get access to certain Nabu information from the cloud.
                - Example:
 
                        NSURL *authorizationURL = [[RzDataManager sharedDataManager] authorizationURLForAppID:@"j293kalc49al0k1msmz9ks0ag8cdd0a0ca"
                                                                                                     andScope:@"fitness"
                                                                                     withAppURISchemeCallback:@"RZOrg"
 
                        [[UIApplication sharedApplication] openURL:authorizationURL];
 */
-(NSURL *)authorizationURLForAppID:(NSString *)appId
                            andScope:(NSString *)appScope
            withAppURISchemeCallback:(NSString *)appURICallback;



/**
 *  Performs validation of the authorization url response from Razer Nabu Utility App.
 *
 *  @param urlResponse This data parameter is a Base64 encoded string which is composed of the Refresh Token, Access Token and other information that were returned from Razer Nabu Utility App after authorization.
 *
 *  @deprecated use NabuDataManager#validateURLResponse:withCompletion:
 */
-(void)validateURLResponse:(NSURL *)urlResponse
                   withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use validateURLResponse: withCompletion:");


/**
 *  Performs validation of the authorization url response from Razer Nabu Utility App.
 *
 *  @param urlResponse This data parameter is a Base64 encoded string which is composed of the Refresh Token, Access Token and other information that were returned from Razer Nabu Utility App after authorization.
 */
-(void)validateURLResponse:(NSURL *)urlResponse
                   withCompletion:(void(^)(NSError *error))completion;


/**
 *  Checks if the app is Authorized.
 *
 *  @param blk Returns: kRefreshAuthorizationTokenFailed = 0, kRefreshAuthorizationTokenSuccess = 1 or kOperationPermissionDenied = 9999
 *
 *  @deprecated use NabuDataManager#checkAppAuthorizationStatusWithCompletion:
 */
-(void)checkAppAuthorizedWithBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use checkAppAuthorizationStatusWithCompletion:");

/**
 *  Check current authorization status of your application.
 *  
 *  @param completion Returns: status as kRefreshAuthorizationTokenFailed = 0, kRefreshAuthorizationTokenSuccess = 1 or kOperationPermissionDenied = 9999
 */
-(void)checkAppAuthorizationStatusWithCompletion:(void(^)(AuthenticationStatus status, NSError *error))completion;

/**
 *  This will query the list of bands that is associated to the user's razer account.
 *
 *  @deprecated use NabuDataManager#getNabuBandListWithCompletion:
 */
-(void)getBandListWithBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getNabuBandListWithCompletion:");

/**
 *  This will check with the NabuAPI and return an array of NabuBand objects for all bands associated with the user's account.
 *
 */
-(void)getNabuBandListWithCompletion:(void(^)(NSArray *arrayOfNabuBands, NSError *error))completion;

/**
 *  Razer Nabu Utility App will send fitness data from Nabu band to the cloud. Use this method to get those records and specify the number of records you want to retrieve.
 *  @param numberOfRecords For the number of records, the user can request up to 7 days (maximum no_of_records = 2016) of historical data
            - Example:
 
                    If you want to get 2016 records of fitness data:
 
                    [[NabuDataManager sharedDataManager] getFitnessDataWithNumberOfRecords:@"2016"];
 *
 *  @deprecated use NabuDataManager#getFitnessDataFor:withCompletion:
 */

-(void)getFitnessDataWithNumberOfRecords:(NSString *)numberOfRecords
                                 withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getFitnessDataFor:withCompletion:");

/**
 *  Retrieve fitness data from NabuAPI. Request fitness data based on the last set of records.
 *
 *  @param numberOfRecords For the number of records, the user can request up to 7 days (maximum no_of_records = 2016) of historical data
            - Example:
 
                    If you wanted to get 2016 records of fitness data:
 
                    [[NabuDataManager sharedDataManager] getFitnessDataFor:2016 withCompletion:(void(^)(NSArray *arrayOfNabuFitnessData))completion];
 */

-(void)getFitnessDataFor:(NSInteger)numberOfRecords
          withCompletion:(void(^)(NSArray *arrayOfNabuFitnessData, NSError *error))completion;


/**
 *  Razer Nabu Utility App will send fitness data from Nabu band to the cloud. Use this method to get those records and specify the date you want to retrieve. User can request up to 7 days of data.
 *
 *  @param date The format for the date should be in Unix Timestamp.
            - Example:
 
                    If you want to get the fitness data for the date(Mon, 02 Jun 2014 11:49:18 GMT), you will say:
 
                    [[NabuDataManager sharedDataManager] getFitnessDataByDate:@"1401709762" withBlock:blk];
 *
 *  @deprecated use NabuDataManager#getFitnessDataWithStartTime:endTime:withCompletion:
 */

-(void)getFitnessDataByDate:(NSString *)date
                    withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getFitnessDataWithStartTime:endTime:withCompletion:");


/**
 *  Razer Nabu Utility App will send fitness data from the Nabu band to the cloud. Use this method to access the fitness data from the Razer Nabu Cloud Service
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format.
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format.
            - Example:
 
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getFitnessDataWithStartTime:@"1394779942" endTime:@"1395643942" withBlock:blk];
 *
 *  @deprecated use NabuDataManager#getFitnessDataWithStartTime:endTime:withCompletion:
 */

-(void)getFitnessDataWithStartTime:(NSString *)startTime
                             endTime:(NSString *)endTime
                           withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getFitnessDataWithStartTime:endTime:withCompletion:");

/**
 *  Retrieve fitness data from NabuAPI. endDateInEpoch is optional use 0 if not using, not specifying this will result in all fitnessData for a given day. Request fitness data based on a given start and end time.
 *
 *  @param dateInEpoch Start time of your query. This value must be in Unix Timestamp format(Epoch time).
 *  @param endDateInEpoch   End time of your query. This value must be in Unix Timestamp format(Epoch time).
            - Example:
 
                - Request data for this period
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getFitnessDataWithStartTime:1394779942 endTime:1395643942 withCompletion:blk];
 
                or
 
                - Request all data for this day
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    [[NabuDataManager sharedDataManager] getFitnessDataWithStartTime:1394779942 endTime:0 withCompletion:blk];
 */
-(void)getFitnessDataWithStartTime:(NSInteger)dateInEpoch
                           endTime:(NSInteger)endDateInEpoch
                    withCompletion:(void(^)(NSArray *arrayOfNabuFitnessData, NSError *error))completion;





/**
 *  Razer Nabu Utility App will send fitness data from Nabu band to the cloud. Use this method to get those records and specify the number of days you want to retrieve.
 *
 *  @param numberOfDays For the number of days, user can request up to 12 months of (Maximum : days = 370) history data. For each day, server returns the aggregated steps/floors/calories/distances.
            - Example:
 
                    If you want to get fitness history data for the past 100 days:
 
                    [[NabuDataManager sharedDataManager] getFitnessHistoryDataForNumberOfDays:@"100"];
 *
 *  @deprecated use NabuDataManager#getFitnessHistoryForNumberOfDays:withCompletion:
 */
-(void)getFitnessHistoryDataForNumberOfDays:(NSString *)numberOfDays
                                    withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getFitnessHistoryForNumberOfDays:withCompletion:");


/**
 *  Retrieve historical fitness data from NabuAPI. Request fitness history for a given number of days. The server returns the aggregated data (steps/floors/calories/distances) for each day.
 *
 *  @param numberOfDays For the number of days, user can request up to 12 months of (Maximum : days = 370) history data. For each day, server returns the aggregated steps/floors/calories/distances.
            - Example:
 
                    If you want to get fitness history data for the past 100 days:
 
                    [[NabuDataManager sharedDataManager] getFitnessHistoryForNumberOfDays:100 withCompletion:blk];
 */
-(void)getFitnessHistoryForNumberOfDays:(NSInteger)numberOfDays
                         withCompletion:(void(^)(NSArray *arrayOfNabuFitnessHistoryDataObjects, NSError *error))completion;


/**
 *  Retrieve historical fitness data from NabuAPI. Request fitness history based on a given start and end time. The server returns the aggregated data(steps/floors/calories/distances)for each day.
 *
 *  @deprecated use NabuDataManager#getFitnessHistoryDataForStartTime:endTime:withCompletion:
 */
-(void)getFitnessHistoryDataWithStartTime:(NSString *)startTime
                                    endTime:(NSString *)endTime
                                  withBlock:(NabuCompletionBlock)blk  DEPRECATED_MSG_ATTRIBUTE("Use getFitnessHistoryDataForStartTime:endTime:withCompletion");

/**
 *  Retrieve historical fitness data from NabuAPI. Request fitness history based on a given start and end time. The server returns the aggregated data(steps/floors/calories/distances)for each day.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format(Epoch time).
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format(Epoch time).
                - Example:
 
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getFitnessHistoryDataForStartTime:@"1394779942" endTime:@"1395643942" withCompletion:blk];
 */
-(void)getFitnessHistoryDataForStartTime:(NSInteger)epochStartTime
                                 endTime:(NSInteger)epochEndTime
                          withCompletion:(void(^)(NSArray *arrayOfNabuFitnessHistoryDataObjects, NSError *error))completion;


/**
 *  Retrieve sleep data from NabuAPI. Request sleep data based on a given start and end time.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format.
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format.
            - Example:
        
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getSleepTrackerDataWithStartTime:@"1394779942" endTime:@"1395643942"];
 *
 *  @deprecated use NabuDataManager#getSleepTrackerDataWithStartTime:endTime:withCompletion:
 */
-(void)getSleepTrackerDataWithStartTime:(NSString *)startTime
                                  endTime:(NSString *)endTime
                                withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getSleepTrackerDataWithStartTime:endTime:withCompletion:");


/**
 *  Retrieve sleep data from NabuAPI. Request sleep data based on a given start and end time.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format(Epoch time).
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format(Epoch time).
 *  @param completion Completion block that outputs an array of NabuSleepTrackerData objects.
            - Example:
 
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getSleepTrackerDataWithStartTime:@"1394779942" endTime:@"1395643942" withCompletion:blk];
 *
 */
-(void)getSleepTrackerDataWithStartTime:(NSInteger)epochStartTime
                                endTime:(NSInteger)epochEndTime
                         withCompletion:(void(^)(NSArray *arrayOfSleepTrackerDataObjects, NSError *error))completion;

/**
 *  Retrieve sleep data from NabuAPI. Request sleep data based on a given number of days.
 *
 *  @param numberOfDays The number of days you wish to retrieve the sleep history data. User can request up to 370 days history data. For each day, server returns the aggregated sleep data
            - Example:
 
                    Number of Days = 370
 
                    [[NabuDataManager sharedDataManager] getSleepHistoryDataWithNumberOfDays:@"370"];
 *
 *  @deprecated use NabuDataManager#getSleepHistoryDataWithNumberOfDays:withCompletion:
 */
-(void)getSleepHistoryDataWithStartTime:(NSString *)numberOfDays
                                withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getSleepHistoryDataWithNumberOfDays:withCompletion:");

/**
 *  Retrieve historical sleep data from NabuAPI. Request sleep history for a given number of days. The server returns the aggregated data for each day.
 *
 *  @param numberOfDays For the number of days, the user can request up to 12 months(Maximum: days = 370)of historical data.
 *  @param completion Completion block that outputs an array of NabuSleepHistoryData objects.
            - Example:
     
                    Number of Days = 370
     
                    [[NabuDataManager sharedDataManager] getSleepHistoryDataWithNumberOfDays:370 withCompletion:blk];
 *
 */
-(void)getSleepHistoryDataWithNumberOfDays:(NSInteger)numberOfDays
                            withCompletion:(void(^)(NSArray *arrayOfNabuSleepHistoryDataObjects, NSError *error))completion;

/**
 *  Retrieve historical sleep data from NabuAPI. Request sleep history based on a given start and end time. The server returns the aggregated data for each day.
 *
 *  @deprecated use NabuDataManager#getSleepHistoryDataWithStartTime:endTime:withCompletion:
 */
-(void)getSleepHistoryDataWithStartTime:(NSString *)startTime
                                  endTime:(NSString *)endTime
                                withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Use getSleepHistoryDataWithStartTime:endTime:withCompletion:");


/**
 *  Retrieve historical sleep data from NabuAPI. Request sleep history based on a given start and end time. The server returns the aggregated data for each day.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format(Epoch time).
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format(Epoch time).
            - Example:
 
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getSleepHistoryDataWithStartTime:1394779942 endTime:1395643942 withCompletion:];
 */
-(void)getSleepHistoryDataWithStartTime:(NSInteger)startTime
                                endTime:(NSInteger)endTime
                         withCompletion:(void(^)(NSArray *arrayOfNabuSleepHistoryDataObjects, NSError *error))completion;


/**
 *  Retrieve Hi Five data from NabuAPI. Use this method to identify any Hi Five requests that the Nabu Band has made within a given date range.
 *  You can request up to 7 Days worth of data.
 *  NOTE: Your application must have been installed on both user devices at the time of the Hi Five in order to recieve data.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format.
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format.
            - Example:

                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT

                    [[NabuDataManager sharedDataManager] getHiFiveDataWithStartTime:@"1394779942" endTime:@"1395643942"];
 *
 *  @deprecated Hi-Five has changed to Handshake. Use NabuDataManager#getHandshakeDataWithStartTime:endTime:withCompletion:
 */
-(void)getHiFiveDataWithStartTime:(NSString *)startTime
                            endTime:(NSString *)endTime
                          withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Hi-Five has been removed. Please use handshake feature instead. Alternative method: getHandshakeDataWithStartTime:endTime:withCompletion");


/**
 *  Retrieve Handshake data from NabuAPI. 
 *  NOTE: Your application must have been installed on both user devices at the time of the handshake in order to recieve data.
 *  
 *  Use this method to identify any Handshake requests that the Nabu Band has made within a given date range.
 *  You can request up to 7 Days worth of data.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format(Epoch time).
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format(Epoch time).
            - Example:
 
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getHandshakeDataWithStartTime:@"1394779942" endTime:@"1395643942" withCompletion:];
 */

-(void)getHandshakeDataWithStartTime:(NSInteger)startTime
                             endTime:(NSInteger)endtime
                      withCompletion:(void(^)(NSArray *arrayOfHandshakes, NSError *error))completion;


/**
 *  Razer Nabu Utility App will send pulse data of all detected Nabu bands to the server. Use this method to get those records specifying start time and end time in your query.
 *  NOTE: Your application must have been installed on both user devices at the time of the pulse in order to recieve data.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format.
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format.
            - Example:

                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT

                    [[NabuDataManager sharedDataManager] getPulseDataWithStartTime:@"1394779942" endTime:@"1395643942"];
 *
 * @deprecated use NabuDataManager#getPulseDataWithStartTime:endTime:withCompletion:
 */
-(void)getPulseDataWithStartTime:(NSString *)startTime
                           endTime:(NSString *)endTime
                         withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use getPulseDataWithStartTime:endTime:withCompletion:");


/**
 *  Razer Nabu Utility App will send pulse data of all detected Nabu bands to the server. Use this method to get those records specifying start time and end time in your query.
 *  NOTE: Your application must have been installed on both user devices at the time of the pulse in order to recieve data.
 *
 *  @param startTime Start time of your query. This value must be in Unix Timestamp format.
 *  @param endTime   End time of your query. This value must be in Unix Timestamp format.
            - Example:
 
                    Start Time is Fri, 14 Mar 2014 06:52:22 GMT
                    End Time is Mon, 24 Mar 2014 06:52:22 GMT
 
                    [[NabuDataManager sharedDataManager] getPulseDataWithStartTime:@"1394779942" endTime:@"1395643942"];
 */
-(void)getPulseDataWithStartTime:(NSInteger)startTime
                           endTime:(NSInteger)endTime
                    withCompletion:(void(^)(NSArray *arrayOfPulses, NSError *error))completion;

/**
 *  Use this method to get the current user's profile information. Note that certain information can be retrieved using this call. If you want all the information, you can get it through the Razer Nabu Utility App.
            - NabuUserProfile object contains:
 
                        NSString *nickName;
                        NSString *avatar;
                        NSString *birthDay;
                        NSString *birthMonth;
                        NSString *birthYear;
                        NSString *gender;
                        NSString *height;
                        NSString *weight;
                        NSString *unit;
 *
 *  @deprecated use NabuDataManager#getUserProfileWithCompletion:
 */
-(void)getUserProfileWithBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use getUserProfileWithCompletion:");


/**
 *  Use this method to get the current user's profile information. Note that certain information can be retrieved using this call. If you want all the information, you can get it through the Razer Nabu Utility App.
 */
-(void)getUserProfileWithCompletion:(void(^)(NabuUserProfile *user, NSError *error))completion;


/**
 *  Use this method to send notification to the band from your app.
 *
 *  @param notificationObj A nabu notification object.

             - Example:
                    NabuNotification *note = [NabuNotification notificationWithMessage:@"Hello World" andIconResID:@"smiley"];
                    [[NabuDataManager sharedDataManager] sendNotificationToBand:note withBlock:nil];
 *
 *  @deprecated use NabuDataManager#sendNotificationToBand:withCompletion:
 */
-(void)sendNotificationToBand:(NabuNotification *)notificationObj withBlock:(NabuCompletionBlock)blk  DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use sendNotificationToBand:withCompletion:");


/**
 *  Use this method to send notification to the band from your app.
 *
 *  @param notificationObj A nabu notification object.
 
            - Example:
                    NabuNotification *note = [NabuNotification notificationWithMessage:@"Hello World" andIconResID:@"smiley"];
                    [[NabuDataManager sharedDataManager] sendNotificationToBand:note withCompletion:nil];
 
 */
-(void)sendNotificationToBand:(NabuNotification *)notification withCompletion:(void(^)(BOOL success, NSError *error))completion;


/**
 *  Use this method to create/update your own clipboard.
 *
 *  @deprecated - Use NabuClipboardManager#writePublicData:withPrivateData:toClipboardWithWriteMessage:withCompletion:
 */
-(void)createUpdateMyClipboardWithMessage:(NSString *)message
                                 publicData:(NSData *)publicData
                                privateData:(NSData *)privateData
                                  withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use [NabuClipboardManager writePublicData:withPrivateData:toClipboardWithWriteMessage:withCompletion:");

/**
 *  Use this method to delete your own clipboard.
 *
 *  @deprecated - Use NabuClipboardManager#deleteClipboardWithCompletion:
 */
-(void)deleteMyClipboardWithBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use NabuClipboardManager deleteClipboardWithCompletion:");


/**
 *  Use this method to get your own clipboard.
 *
 *  @deprecated - Use NabuClipboardManager#getClipboardForCurrentUserWithCompletion:
 */
-(void)getMyClipboardWithBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use [NabuClipboardManager getClipboardForCurrentUserWithCompletion:]");


/**
 *  Use this method to get other users' clipboards.
 *
 *  @param openIds  Array of openIds.
                    Limited to a maximum 20 openIds per query.
 
 *  @deprecated - Use NabuClipboardManager#getClipboardForUsersWithOpenIDs:withCompletion:
 */
-(void)getClipboardsWithOpenIds:(NSArray *)openIds withBlock:(NabuCompletionBlock)blk DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use [NabuClipboard Manager getClipboardForUsersWithOpenIDs: withCompletion:]");

@end
