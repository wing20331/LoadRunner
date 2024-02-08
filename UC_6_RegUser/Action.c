Action()
{	
int y;
int i;
char *str;
char *str2 =lr_eval_string("{letter}");

char *str3;
char *str4 =lr_eval_string("{letter}");
	
for(i = 0; i < 10; i++) {
    str = lr_eval_string("{letter}");
    
    lr_param_sprintf("login1", "%s%s", str2, str);
    str2 = lr_eval_string("{login1}");
}


	
for(y = 0; y < 10; y++) {
    str3 = lr_eval_string("{letter}");
    
    lr_param_sprintf("password1", "%s%s", str4, str3);
    str4 = lr_eval_string("{password1}");
}

lr_start_transaction("UC_6_addUser");

	
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
		
		lr_start_transaction("SignUp");


	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t2.inf", 
		LAST);

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

		
	

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value={login1}", ENDITEM, 
		"Name=password", "Value={password1}", ENDITEM, 
		"Name=passwordConfirm", "Value={password1}", ENDITEM, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={city}", ENDITEM, 
		"Name=register.x", "Value=37", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);

	
	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_find("Text=>Welcome, <b>{login1}</b>",
		LAST);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("SignUp", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("LogOut");

	web_revert_auto_header("Sec-Fetch-User");

	
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

	lr_end_transaction("UC_6_addUser", LR_AUTO);

	
	return 0;
}