#ifndef __Logger_hpp_2018_07_17_20_02
#define __Logger_hpp_2018_07_17_20_02

#define DEBUG

#ifdef DEBUG
#define LOG_ENTER term.print(Color::GRAY,"LOG: ",__FUNCTION__, " (enter)",endline)
#define LOG_EXIT term.print(Color::GRAY,"LOG: ",__FUNCTION__," (return)",endline)
#endif
#endif