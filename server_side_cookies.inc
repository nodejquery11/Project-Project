Date: 29/Aug/16
SESSIONS: Server side cookies

Server side cookies are known as "sessions". The website in this case stores a single cookie on the browser containing a unique Session Identifier. Status information (foo=10 and bar=20 above) are stored on the server and the Session Identifier is used to match the request with the data stored on the server.

Pros and Cons
Below pros and cons of the solutions. These are the first that comes to my mind, there are surely others.

Cookie Pros:

scalability: all the data is stored in the browser so each request can go through a load balancer to different webservers and you
have all the informations needed to fullfill the request;
>they can be accessed via javascript on the browser;
>not being on the server they will survive server restarts;
>RESTful: requests don't depend on server state

Cookie Cons:
>storage is limited to 80 KB (20 cookies, 4 KB each)
>secure cookies are not easy to implement: take a look at the paper A secure cookie protocol

Session Pros:
>generally easier to use, in PHP there's probably not much difference.
>unlimited storage
Session Cons:
>more difficult to scale
>on web server restarts you can lose all sessions or not depending on the implementation 
>not RESTful

Note:
1.are call server side cookies. In this case single cookie store in the browser cantaining the unique session identifier. Status info store on the server and session identifier use to match the request.
2.You can use both session & cookie to store, authentication data, user preference etc.

http://stackoverflow.com/questions/6922145/what-is-the-difference-between-server-side-cookie-and-client-side-cookie 

Kind of DB connection 
1.Presistance Connection
2.Non-persistance Connection
persistance connection: is the connection string or link which don't ends when your's script is end. In persistance connection php check that persistance connection is already running, if yes then it will use the same otherwise it create the new connection or link with same details.

How web server works with PHP?
There are three way, web server utilize the PHP generate pages
1.PHP as CGI(Common Gateway Interface)"wrapper". in this instacnce web server distroy all pages and close all connection or link so nothing will be exist after distroy.
2.Run PHP as a module in multiprocess web server like Apache server. In this case one process call parent process and rest all child process. You can finished one child process and if you request another process then it use as the another child process.
3.PHP as plugin for multithread webserver.

Kind of cockies
1. persistance cokies[which are written on hard-disk or drive. It will be alive till its expiry date will not come.]
2. temparary cockies /session cookies/transient cookies [Once browser has been close, it will distroy]
a.You can set the cookies using "setcookie" and "setrawcookie"
b.cookie must be use before header, as both have same limitation either you need to use output buffering function
c.global variable of cookie is $_COOKIE
d.unset(cookie_variable) //to delete the cookie
setcookie($name, $value, $expire_timestamp, $path, $domain, $secure_https, $httponly)

Header
a.redirect: header("Location: $url");
b.download dialog: header("content-type: application/pdf/txt");
		   header("content-disposition:attachment; filename='*.pdf/*.txt'");
c.caching directives:header("cache-control: no-cache, must-revalidate");
		   header("Expires:$date");
Additionally, session_cache_limiter() and the session.cache_limiter configuration setting can be used to automatically generate the correct caching-related headers when sessions are being used. 



