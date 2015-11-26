//
//  MQChatViewManager.h
//  MeiQiaSDK
//
//  Created by ijinmao on 15/10/27.
//  Copyright © 2015年 MeiQia Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MQChatViewController.h"
#import "MQChatViewConfig.h"

/**
 * @brief 客服聊天界面的配置类
 *
 * 开发者可以通过MQChatViewManager中提供的接口，来对客服聊天界面进行自定义配置；
 */
@interface MQChatViewManager : NSObject

/**
 * 在一个ViewController中Push出一个客服聊天界面
 * @param viewController 在这个viewController中push出客服聊天界面
 */
- (MQChatViewController *)pushMQChatViewControllerInViewController:(UIViewController *)viewController;

/**
 * 在一个ViewController中Present出一个客服聊天界面的Modal视图
 * @param viewController 在这个viewController中push出客服聊天界面
 */
- (MQChatViewController *)presentMQChatViewControllerInViewController:(UIViewController *)viewController;

/**
 * 将客服聊天界面移除
 */
- (void)disappearMQChatViewController;

/**
 *  设置是否开启自定义聊天界面的坐标
 *
 *  @param enable YES 自定义 NO 不自定义
 */
- (void)enableCustomChatViewFrame:(BOOL)enable;

/**
 * 设置客服聊天界面的坐标
 * @param viewFrame 客服聊天界面的坐标
 */
- (void)setChatViewFrame:(CGRect)viewFrame;

/**
 * 增加消息中可选中的数字的正则表达式，用于匹配消息，满足条件段落可以被用户点击。
 * @param numberRegex 数字的正则表达式
 */
- (void)setMessageNumberRegex:(NSString *)numberRegex;

/**
 * 增加消息中可选中的链接的正则表达式，用于匹配消息，满足条件段落可以被用户点击。
 * @param numberRegex 链接的正则表达式
 */
- (void)setMessageLinkRegex:(NSString *)linkRegex;

/**
 * 增加消息中可选中的email的正则表达式，用于匹配消息，满足条件段落可以被用户点击。
 * @param emailRegex email的正则表达式
 */
- (void)setMessageEmailRegex:(NSString *)emailRegex;

/**
 * 设置顾客第一次进入界面显示的欢迎文字；
 * @param tipText 提示文字
 */
- (void)setChatWelcomeText:(NSString *)welcomText;

/**
 *  设置客服的名字
 *
 *  @param agentName 客服名字
 */
- (void)setAgentName:(NSString *)agentName;

/**
 * 设置收到消息的声音；
 * @param soundFileName 声音文件
 */
- (void)setIncomingMessageSoundFileName:(NSString *)soundFileName;

/**
 * 显示的历史聊天消息是否去主动同步服务端的消息记录。因为有可能顾客在其他客户端产生了消息记录，如果设置为NO，则SDK本地消息会与服务端实际的历史消息不相符；默认NO
 * @warning 如果开启同步，将会产生一定网络请求。所以建议顾客端只使用美洽SDK的用户保持默认值
 * @warning 如果开启同步，下拉获取历史消息则会从服务端去获取；如果关闭同步，下拉获取历史消息则是从SDK本地数据库中获取；
 * @param enable YES:同步 NO:不同步
 */
- (void)enableSyncServerMessage:(BOOL)enable;

/**
 * 是否显示事件状态流；事件的状态流有：初始化对话、对话被转接给其他客服、对话超时、客服主动结束了对话、客服正在输入；
 * @param enable YES:开启事件状态流 NO:关闭事件状态流
 */
- (void)enableEventDispaly:(BOOL)enable;

/**
 * 是否支持发送语音消息；
 * @param enable YES:支持发送语音消息 NO:不支持发送语音消息
 */
- (void)enableSendVoiceMessage:(BOOL)enable;

/**
 * 是否支持发送图片消息；
 * @param enable YES:支持发送图片消息 NO:不支持发送图片消息
 */
- (void)enableSendImageMessage:(BOOL)enable;

/**
 *  客服聊天界面打开时，收到新消息，是否显示收到新消息提示
 *
 * @param enable YES:支持 NO:不支持
 */
- (void)enableShowNewMessageAlert:(BOOL)enable;

/**
 * 是否支持客服头像的显示；
 * @param enable YES:支持 NO:不支持
 */
- (void)enableAgentAvatar:(BOOL)enable;

/**
 *  是否支持当前顾客头像的显示
 *
 * @param enable YES:支持 NO:不支持
 */
- (void)enableClientAvatar:(BOOL)enable;

/**
 * 是否支持自定义录音的界面；
 * @param enable YES:支持 NO:不支持
 */
- (void)enableCustomRecordView:(BOOL)enable;

/**
 * 是否开启接受/发送消息的声音；
 * @param enable YES:开启声音 NO:关闭声音
 */
- (void)enableMessageSound:(BOOL)enable;

/**
 *  是否开启下拉刷新（顶部刷新）
 *
 * @warning 如果开发者要禁用下拉刷新，则需要将enableTopPullRefresh和enableTopAutoRefresh都置为false
 * @param enable YES:支持 NO:不支持
 */
- (void)enableTopPullRefresh:(BOOL)enable;

/**
 *  是否开启上拉刷新（底部刷新）
 *
 * @param enable YES:支持 NO:不支持
 */
- (void)enableBottomPullRefresh:(BOOL)enable;

/**
 *  是否开启顶部自动刷新历史消息
 *
 * @warning 如果开发者要禁用下拉刷新，则需要将enableTopPullRefresh和enableTopAutoRefresh都置为false
 * @param enable YES:支持 NO:不支持
 */
- (void)enableTopAutoRefresh:(BOOL)enable;

/**
 *  是否开启圆形头像
 *
 * @param enable YES:支持 NO:不支持
 */
- (void)enableRoundAvatar:(BOOL)enable;

/**
 *  是否支持欢迎语
 *
 * @param enable YES:支持 NO:不支持
 */
- (void)enableWelcomeChat:(BOOL)enable;

/**
 * 设置发送过来的message的文字颜色；
 * @param textColor 文字颜色
 */
- (void)setIncomingMessageTextColor:(UIColor *)textColor;

/**
 *  设置发送过来的message气泡颜色
 *
 *  @param bubbleColor 气泡颜色
 */
- (void)setIncomingBubbleColor:(UIColor *)bubbleColor;

/**
 * 设置发送出去的message的文字颜色；
 * @param textColor 文字颜色
 */
- (void)setOutgoingMessageTextColor:(UIColor *)textColor;

/**
 *  设置发送的message气泡颜色
 *
 *  @param bubbleColor 气泡颜色
 */
- (void)setOutgoingBubbleColor:(UIColor *)bubbleColor;

/**
 * 设置事件流的显示文字的颜色；
 * @param textColor 文字颜色
 */
- (void)setEventTextColor:(UIColor *)textColor;

/**
 * 设置导航栏上的元素颜色；
 * @param tintColor 导航栏上的元素颜色
 */
- (void)setNavigationBarTintColor:(UIColor *)tintColor;

/**
 * 设置导航栏的背景色；
 * @param barColor 导航栏背景颜色
 */
- (void)setNavigationBarColor:(UIColor *)barColor;

/**
 *  设置下拉/上拉刷新的颜色
 *
 *  @param pullRefreshColor 颜色
 */
- (void)setPullRefreshColor:(UIColor *)pullRefreshColor;

/**
 * 设置客服的缺省头像图片；
 * @param image 头像image
 */
- (void)setAgentDefaultAvatarImage:(UIImage *)image;

/**
 * 设置顾客的缺省头像图片；
 * @param image 头像image
 */
- (void)setClientDefaultAvatarImage:(UIImage *)image;

/**
 * 设置底部自定义发送图片的按钮图片；
 * @param image 按钮image
 */
- (void)setPhotoSenderImage:(UIImage *)image;

/**
 * 设置底部自定义发送语音的按钮图片；
 * @param image 按钮image
 */
- (void)setVoiceSenderImage:(UIImage *)image;

/**
 * 设置自定义客服的消息气泡（发送过来的消息气泡）的背景图片；
 * @param bubbleImage 气泡图片
 */
#warning 增加气泡图片的比例限制
- (void)setIncomingBubbleImage:(UIImage *)bubbleImage;

/**
 * 设置自定义顾客的消息气泡（发送出去的消息气泡）的背景图片；
 * @param bubbleImage 气泡图片
 */
#warning 增加气泡图片的比例限制
- (void)setOutgoingBubbleImage:(UIImage *)bubbleImage;

/**
 *  设置导航栏左键的图片
 *
 *  @param leftButtonImage 左键图片
 */
- (void)setNavLeftButtonImage:(UIImage *)leftButtonImage;

/**
 *  设置模态试图的导航栏左键的图片
 *
 *  @param leftButtonImage 左键图片
 */
- (void)setModalViewNavLeftButtonImage:(UIImage *)leftButtonImage;

/**
 *  设置导航栏右键的图片
 *
 *  @param rightButtonImage 左键图片
 */
- (void)setNavRightButton:(UIButton *)rightButton;

/**
 *  设置录音的最大时长
 *
 *  @param recordDuration 时长
 */
- (void)setMaxRecordDuration:(NSTimeInterval)recordDuration;

#ifdef INCLUDE_MEIQIA_SDK

/**
 *  设置分配给指定的客服id
 *
 *  @param agentId 客服id
 */
- (void)setScheduledAgentToken:(NSString *)agentToken;

/**
 *  设置分配给指定的客服组id
 *
 *  @warning 如果设置了分配给客服id，以分配给客服id为优先
 *  @param groupId 客服组id
 */
- (void)setScheduledGroupToken:(NSString *)groupToken;

/**
 *  设置登录客服的开发者自定义id，设置该id后，聊天将会以该自定义id的顾客上线
 *
 *  @warning 如果setLoginMQClientId接口，优先使用setLoginMQClientId来进行登录
 *  @param customizedId 开发者自定义id
 */
- (void)setLoginCustomizedId:(NSString *)customizedId;

/**
 *  设置登录客服的顾客的id，设置该id后，聊天将会以该顾客id的顾客上线
 *
 *  @warning 如果调用了setLoginCustomizedId接口，优先使用此接口来进行登录
 *  @param MQClientId 顾客id
 */
- (void)setLoginMQClientId:(NSString *)MQClientId;


#endif


@end