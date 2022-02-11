package data

import (
	"time"
)

type Thread struct {
	Id		 int
	Uuid	 string
	Topic	 string
	UserId	 string
	CreateAt time.Time
}
