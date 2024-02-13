Action()
{
	
	int i;
	int rndint = atoi(lr_eval_string("{rnd}"));
	
	
	lr_start_transaction("UC_5_Delete");

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
		
		lr_think_time(5);
		
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
		"Text=Welcome, <b>{login}</b>",
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
	
	lr_think_time(5);
	
	 lr_start_transaction("GoToTicket");

	web_reg_find("Search=Body",
		"Text=User wants the intineraries.",
		LAST);

    web_reg_save_param("c_flightids",
    "lb=<input type=\"hidden\" name=\"flightID\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);


    web_reg_save_param("c_cgifields",
    "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);
	 
	 

   web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

    lr_end_transaction("GoToTicket", LR_AUTO);
    
    
    
    if(rndint >= atoi(lr_eval_string("{c_flightids_count}"))){
    	rndint = atoi(lr_eval_string("{c_flightids_count}"));
    }

  

    lr_save_string("", "c_buffer");

    for (i=1;i<=rndint;i++)
    {
        lr_param_sprintf("c_buffer", "%s%d=on&", lr_eval_string("{c_buffer}"), i);
    }




    for (i=1;i<=atoi(lr_eval_string("{c_flightids_count}"));i++)
    {
        lr_param_sprintf("c_buffer",
        "%sflightID=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("c_flightids",
        i));

        lr_param_sprintf("c_buffer",
        "%s.cgifields=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("c_cgifields",
        i));
    }


    lr_save_string(lr_eval_string("{c_buffer}removeFlights.x=36&removeFlights.y=4"), "c_wcr");

    lr_start_transaction("DeleteTicket");


    lr_save_string(lr_eval_string(lr_eval_string("{c_flightids_{c_flightids_count}}")),
    "c_cancelflight");

    web_reg_find("Text={c_cancelflight}", "Fail=Found", LAST);
    

    web_custom_request("itinerary.pl_2",
    "URL=http://localhost:1080/cgi-bin/itinerary.pl",
    "Method=POST",
    "Resource=0",
    "RecContentType=text/html",
    "Referer=http://localhost:1080/cgi-bin/itinerary.pl",
    "Snapshot=t23.inf",
    "Mode=HTTP",
    "Body={c_wcr}",
    LAST);

    lr_end_transaction("DeleteTicket", LR_AUTO);
	
	
	
	lr_end_transaction("UC_5_Delete", LR_AUTO);


	return 0;
}