//
//  MQChatViewService.h
//  MeiQiaSDK
//
//  Created by ijinmao on 15/10/28.
//  Copyright © 2015年 MeiQia Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MQBaseMessage.h"
#import <UIKit/UIKit.h>
#import "MQChatViewConfig.h"
#ifdef INCLUDE_MEIQIA_SDK
#import "MQServiceToViewInterface.h"
#endif

@protocol MQChatViewServiceDelegate <NSObject>

/**
 *  获取到了更多历史消息
 */
- (void)didGetHistoryMessagesWithMessagesNumber:(NSInteger)messageNumber;

/**
 *  已经更新了这条消息的数据，通知tableView刷新界面
 */
- (void)didUpdateCellModelWithIndexPath:(NSIndexPath *)indexPath;

/**
 *  通知viewController更新tableView；
 */
- (void)reloadChatTableView;


@end

/**
 * @brief 聊天界面的ViewModel
 *
 * MQChatViewService管理者MQChatViewController中的数据
 */
@interface MQChatViewService : NSObject

#ifdef INCLUDE_MEIQIA_SDK
/**
 *  后端返回的数据的错误委托方法
 */
@property (nonatomic, weak) id<MQServiceToViewInterfaceErrorDelegate> errorDelegate;
#endif

/** MQChatViewService的委托 */
@property (nonatomic, weak) id<MQChatViewServiceDelegate> delegate;

/** cellModel的缓存 */
@property (nonatomic, strong) NSMutableArray *cellModels;

/** 聊天界面的宽度 */
@property (nonatomic, assign) CGFloat chatViewWidth;

/**
 * 获取更多历史聊天消息
 */
- (void)startGettingHistoryMessages;

/**
 * 发送文字消息
 */
- (void)sendTextMessageWithContent:(NSString *)content;

/**
 * 发送图片消息
 */
- (void)sendImageMessageWithImage:(UIImage *)image;

/**
 * 以AMR格式语音文件的形式，发送语音消息
 * @param filePath AMR格式的语音文件
 */
- (void)sendVoiceMessageWithAMRFilePath:(NSString *)filePath;

/**
 * 发送“用户正在输入”的消息
 */
- (void)sendUserInputtingWithContent:(NSString *)content;

/**
 * 重新发送消息
 * @param index 需要重新发送的index
 * @param resendData 重新发送的字典 [text/image/voice : data]
 */
- (void)resendMessageAtIndex:(NSInteger)index resendData:(NSDictionary *)resendData;

/**
 *  更新cellModel中的frame，针对转屏的场景
 */
- (void)updateCellModelsFrame;

/**
 *  发送本地欢迎语消息
 *  @warnning 该消息不需要发送给后端
 */
- (void)sendLocalWelcomeChatMessage;

#ifndef INCLUDE_MEIQIA_SDK
/**
 * 使用MQChatViewControllerDemo的时候，调试用的方法，用于收取和上一个message一样的消息
 */
- (void)loadLastMessage;
#endif

@end