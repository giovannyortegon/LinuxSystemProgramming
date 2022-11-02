package main

import "fmt"

type INotificationFactory interface {
	SendNotification()
	GetSender() ISender
}

type ISender interface {
	GetSenderMethod() string
	GetSenderChannel() string
}

type SMSNotifcation struct {
}

func (SMSNotifcation) SendNotification() {
	fmt.Println("Sending notification SMS")
}

func (SMSNotifcation) GetSender() ISender {
	return SMSNotifcationSender{}
}

type SMSNotifcationSender struct {
}

func (SMSNotifcationSender) GetSenderMethod() string {
	return "SMS"
}

func (SMSNotifcationSender) GetSenderChannel() string {
	return "Twilio"
}

type EmailNotification struct {
}

func (EmailNotification) SendNotification() {
	fmt.Println("Sending Notification EMail")
}

type EmailNotificationSender struct {
}

func (EmailNotificationSender) GetSenderMethod() string {
	return "Email"
}

func (EmailNotificationSender) GetSenderChannel() string {
	return "SES"
}

func (EmailNotification) GetSender() ISender {
	return EmailNotificationSender{}
}

func getNotificationFactry(notificationType string) (INotificationFactory, error) {
	if notificationType == "SMS" {
		return &SMSNotifcation{}, nil
	}
	if notificationType == "Email" {
		return &EmailNotification{}, nil
	}

	return nil, fmt.Errorf("No Notification Type")
}

func SendNotification(f INotificationFactory) {
	f.SendNotification()
}

func getMethod(f INotificationFactory) {
	fmt.Println(f.GetSender().GetSenderChannel())
}

func main() {
	smsFactory, _ := getNotificationFactry("SMS")
	emaiFactory, _ := getNotificationFactry("Email")

	SendNotification(smsFactory)
	SendNotification(emaiFactory)
	getMethod(smsFactory)
	getMethod(emaiFactory)

}
