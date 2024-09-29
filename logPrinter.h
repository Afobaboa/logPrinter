/**
 * @file 
 * For correct working of rhis file
 * use OPEN_LOG() at the beginning 
 * of main() and close it by LOG_SLOSE()
 * before return in main().
 * 
 * Use macroses for convinient
 * using of logginng.
 * 
 * If you want to switch off loging
 * without removing code just add
 * 
 * #define LOG_SWITCH_OFF
 * 
 * in main file, where you are
 * opening log. 
 * 
 * DEFINE IT ONLY BEFORE INCLUDING
 * ANY FILES, ESLE LOG WON'T 
 * BE SWITCHED OFF!!!
 */


#ifndef LOG_PRINTER_H
#define LOG_PRINTER_H


//----------------------------------------------------------------------------------------


#include "logPrinterConfigs.h"


//----------------------------------------------------------------------------------------


/**
 * This function automaticaly gets
 * file, function and line information
 * about plac where it was used and
 * wraps that information into struct Place.
 */
#define GET_PLACE()                \
    (struct Place)                 \
    {                              \
        .file     = __FILE__,      \
        .function = __FUNCTION__,  \
        .line     = __LINE__       \
    }                              \


/**
 * This definition return 
 * name of your variable.
 */
#define GET_NAME(var) #var


//----------------------------------------------------------------------------------------


#ifndef LOG_SWITCH_OFF


/**
 * This function works like LogPrint()
 * but it's automaticaly place GET_PLACE()
 * to arguments. 
 * 
 * That provides you more 
 * convinient syntax.
 */
#define LOG_PRINT(logMode, ...)                  \
    LogPrint(logMode, GET_PLACE(), __VA_ARGS__) 


/**
 * This definition provides you more
 * convinient way to use logOpen().
 * 
 * Also this function will print
 * date, time and place, where and
 * when log was opened.
 */
#define LOG_OPEN()        \
    LogOpen(GET_PLACE()) 


/**
 * This definition provides you more
 * convinient way to use LogClose().
 * 
 * Also this function will print
 * date, time and place, where and
 * when log was closed
 */
#define LOG_CLOSE()        \
    LogClose(GET_PLACE()) 


/**
 * This definition provides you more
 * convnient way to use LogDummyPrint().
 * 
 * This function print your message 
 * without information about place and time
 * to log file.
 */
#define LOG_DUMMY_PRINT(...)                    \
    LogDummyPrint(GET_PLACE(), __VA_ARGS__)    


#else


/** 
 * Where are switching off
 * all log's defines.
 */
#define LOG_PRINT(logMode, ...) 
#define LOG_OPEN() 
#define LOG_CLOSE() 
#define LOG_DUMMY_PRINT(...) 


#endif // LOG_SWITCHING_OFF


//----------------------------------------------------------------------------------------



/**
 * This struct proides you convinient
 * way to keep information about places in code.
 */
struct Place
{
    const char* file;        /**< Name of file.     */
    const char* function;    /**< Name of function. */
    int         line;        /**< Number of line.   */
};


//----------------------------------------------------------------------------------------


/**
 * There are log modes which 
 * used for notes in log records.
 */
enum LOG_MODES 
{
    ERROR,      /**< ERROR   */
    WARNING,    /**< WARNING */
    INFO        /**< INFO    */
};
typedef enum LOG_MODES logMode_t;


/**
 * This colores used for
 * ColoredPrintf() to set
 * needed color.
 */
enum COLORS {
    GREEN,   /**< Green color. */
    RED,     /**< Red color.   */
    YELLOW,  /**< Yellow color */
    WHITE    /**< White color  */
};
typedef enum COLORS color_t;


//----------------------------------------------------------------------------------------


/**
 * This function open log file.
 * If this file is already opened,
 * this function print special message
 * to "logs/emergencyLog.txt".
 * 
 * @param place Place that will be printed
 *              in emergency log file.
 */
void LogOpen(const Place place);


/**
 * This function close log file.
 * If this file is already closeed,
 * this function print special message
 * to "logs/emergencyLog.txt".
 * 
 * @param place Place that will be printed
 *              in emergency log file.
 */
void LogClose(const Place place);


/**
 * This function print your message
 * to "logs/log.txt" by default (you can
 * chane log's output file in defines in logPrinter.cpp). 
 * Also it prints Place where it was used.
 * 
 * @param logMode Note to log message.
 * @param place   Place that will be printed.
 * @param message Message with fomat like in printf(). 
 *                Next arguments will be used in message
 */
void LogPrint(logMode_t logMode, Place place, const char* message, ...);


/**
 * This function print your message to "logs/log.txt" 
 * by default (you can change it in defines in logPrinter.cpp).
 * Message will be printed without time and place.
 */
void LogDummyPrint(const Place place, const char* message, ...);


/**
 * This function is similary
 * to printf(), but this function
 * can print colored text.
 * 
 * @param color Color of text. You have
 * to use something from enum COLORS.
 * @param format Format of your text.
 * You have to use printf() format
 * 
 * Other arguments used for subtitution
 * to format. You have to use as many
 * arguments as you us in format, like 
 * in printf().
 * 
 * @return Count of used other arguments.
 */
int ColoredPrintf(color_t color, const char* format, ...);


/**
 * 
 */
char* GetArrayPrintingFormat(const size_t maxSize);


/**
 * 
 */
void LogPrintELem(void* elemPtr, const size_t elemSize);


//----------------------------------------------------------------------------------------


#endif // LOG_PRINTER_H