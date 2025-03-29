enum EventType : short
{
	EventTypeWindowClose
};

enum EventCategory : short
{

};

#define EVENT_TYPE(eEventType)								\
static inline EventType GetStaticEventType()				\
{															\
	return eEventType;										\
}															\