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
