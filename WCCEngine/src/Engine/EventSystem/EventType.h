enum EventType : short
{
	EventTypeWindowClose,
	EventTypeMouseButton,
	EventTypeMouseButtonPressed
};

enum EventCategory : short
{

};

#define EVENT_TYPE(eEventType)								\
static inline EventType GetStaticEventType()				\
{															\
	return eEventType;										\
}															\