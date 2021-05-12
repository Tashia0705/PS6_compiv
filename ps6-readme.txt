/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Tashia Boddu


Hours to complete assignment: 7+ hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the assignment successfully because all .log files have 
the correct output! Almost all parts should be working. 

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
boost::regex startMessage("( \\(log.c.166\\) server started)");
    - Stores the first logging message using regex. 

boost::regex endMessage(
    "(oejs.AbstractConnector:Started SelectChannelConnector)");
    - Stores the log entry that indicates the completion of 
    the boot up sequence. 

regex_search(str, startMessage) 
    - Compares str of type string extracted from the file to the 
    regular expression startMessage from above.

regex_search(str, endMessage)
    - Compares str of type string extracted from the file to the 
    regular expression endMessage from above.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I start out by initializing regular expressions to the  first and 
last log entries. This is what we'll use to compare the regex to find 
if there's a match in each line of the .log files. I create an output 
file where the resulting data will be sent. I also use a boolean
expression to keep track to incomplete booting (has a start but no 
finish). While each line is being read, I use regex_search to search 
the line to find a match for the starting regular expression (log.c.166).
If there is a match I check to make sure there is no incomplete booting.
If ther is no incomplete booting I output the line number, date, time
and status of the boot to the output file. Once that's done I check use
an else if statement to search the line to find a match for the ending 
regular expression (oejs.Abs...). Once that is found, I calculate the 
duration of the time using posix. And I output the line number, date, 
time and the duration it took to comlepte the boot up sequence. 

/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
Yes I used lambda to get the time from the first 19 characters of
the line

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Tutors: Ben F. 
Classmates: Seyedsepher Madani

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 Had trouble figuring out how to use the posix stuff

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
