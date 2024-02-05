Action()
{
	
	lr_start_transaction("UC_2_SearchTicket");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	
	lr_start_transaction("IndexPage");


/*Correlation comment - Do not change!  Original value='138259.23491292HVVVHAQpDQfiDDDDtczHApcfzDHf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
		web_reg_find("Search=Body",
		"Text=Welcome to the Web Tours site",
		LAST);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_transaction("IndexPage", LR_AUTO);
		
		lr_start_transaction("LogIn");



	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1706808528090\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);


	/*Connection ID 0 received buffer WebSocketReceive0*/

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");
	
	web_reg_find("Search=Body",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t20.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=53", ENDITEM,
		"Name=login.y", "Value=14", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	
	lr_end_transaction("LogIn", LR_AUTO);
	
	lr_start_transaction("GotoFlight");


		
		web_reg_find("Search=Body",
		"Text=Departure City",
		LAST);
		
		web_reg_save_param_regexp(
		"ParamName=Cities",
		"RegExp=>(.+?)</option>",
	    "Ordinal=all",
			LAST);
					
			

	

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_save_string(lr_paramarr_random("Cities"), "city");
	lr_save_string(lr_paramarr_random("Cities"), "city2");
	
	
	while("city" == "city2"){
	lr_save_string(lr_paramarr_random("Cities"), "city2");
	}

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(5);

	
		
		lr_end_transaction("GotoFlight", LR_AUTO);
		
		lr_start_transaction("SearchTiket");
		
		
		
		
		

	web_reg_find("Search=Body",
		"Text=Flight departing from <B>{city}</B> to <B>{city2}</B>",
		LAST);
		
		
		
		
		
	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t22.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={city}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={city2}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value={numpass}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={coach}", ENDITEM,
		"Name=findFlights.x", "Value=64", ENDITEM,
		"Name=findFlights.y", "Value=14", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);
		

		
		lr_end_transaction("SearchTiket", LR_AUTO);
		
		lr_start_transaction("LogOut");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(5);
	
	web_reg_find("Text=Welcome to the Web Tours site",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("LogOut", LR_AUTO);
		
		lr_end_transaction("UC_2_SearchTicket", LR_AUTO);

	return 0;
}
