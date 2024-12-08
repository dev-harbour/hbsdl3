#ifndef SDL_TIMER_CH_
#define SDL_TIMER_CH_

#define SDL_MS_PER_SECOND   1000
#define SDL_US_PER_SECOND   1000000
#define SDL_NS_PER_SECOND   1000000000
#define SDL_NS_PER_MS       1000000
#define SDL_NS_PER_US       1000
#define SDL_SECONDS_TO_NS(S)    (((Uint64)(S)) * SDL_NS_PER_SECOND)
#define SDL_NS_TO_SECONDS(NS)   ((NS) / SDL_NS_PER_SECOND)
#define SDL_MS_TO_NS(MS)        (((Uint64)(MS)) * SDL_NS_PER_MS)
#define SDL_NS_TO_MS(NS)        ((NS) / SDL_NS_PER_MS)
#define SDL_US_TO_NS(US)        (((Uint64)(US)) * SDL_NS_PER_US)
#define SDL_NS_TO_US(NS)        ((NS) / SDL_NS_PER_US)

#endif /* End SDL_TIMER_CH_ */
