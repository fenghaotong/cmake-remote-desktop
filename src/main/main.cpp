
#include "util/CommonHeader.h"
#include "util/winhdr.h"
#include "util/CommandLine.h"
#include "win-system/WinCommandLineArgs.h"

#include "tvnserver-app/TvnService.h"
#include "tvnserver-app/TvnServerApplication.h"
#include "tvnserver-app/QueryConnectionApplication.h"
#include "tvnserver-app/DesktopServerApplication.h"
#include "tvnserver-app/AdditionalActionApplication.h"
#include "tvnserver-app/ServiceControlApplication.h"
#include "tvnserver-app/ServiceControlCommandLine.h"
#include "tvnserver-app/QueryConnectionCommandLine.h"
#include "tvnserver-app/DesktopServerCommandLine.h"

#include "tvncontrol-app/ControlApplication.h"
#include "tvncontrol-app/ControlCommandLine.h"

#include "resource.h"
#include "tvnserver-app/CrashHook.h"
#include "tvnserver-app/NamingDefs.h"

#include "tvnserver-app/WinEventLogWriter.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine, int nCmdShow)
{
    LogWriter preLog(0);

    // Life time of the sysLog must be greater than a TvnService object
    // because the crashHook uses it but fully functional usage possible
    // only after the TvnService object start.
    WinEventLogWriter winEventLogWriter(&preLog);
    CrashHook crashHook(&winEventLogWriter);

    ResourceLoader resourceLoaderSingleton(hInstance);

    CommandLineFormat format[] = {
      { TvnService::SERVICE_COMMAND_LINE_KEY, NO_ARG },

      { ControlCommandLine::CONFIG_APPLICATION, NO_ARG },
      { ControlCommandLine::CONFIG_SERVICE, NO_ARG },
      { ControlCommandLine::SET_CONTROL_PASSWORD, NO_ARG },
      { ControlCommandLine::SET_PRIMARY_VNC_PASSWORD, NO_ARG },
      { ControlCommandLine::CHECK_SERVICE_PASSWORDS, NO_ARG },
      { ControlCommandLine::CONTROL_SERVICE, NO_ARG },
      { ControlCommandLine::CONTROL_APPLICATION, NO_ARG },

      { DesktopServerCommandLine::DESKTOP_SERVER_KEY, NO_ARG },
      { QueryConnectionCommandLine::QUERY_CONNECTION, NO_ARG },

      { AdditionalActionApplication::LOCK_WORKSTATION_KEY, NO_ARG },
      { AdditionalActionApplication::LOGOUT_KEY, NO_ARG },

      { ServiceControlCommandLine::INSTALL_SERVICE },
      { ServiceControlCommandLine::REMOVE_SERVICE },
      { ServiceControlCommandLine::REINSTALL_SERVICE },
      { ServiceControlCommandLine::START_SERVICE },
      { ServiceControlCommandLine::STOP_SERVICE }
    };

    CommandLine parser;

    // We really don't care about parsing result, we only need the first specified key.

    StringStorage firstKey(_T(""));

    cout << lpCmdLine << endl;
   
    try {
        WinCommandLineArgs args(lpCmdLine);
        parser.parse(format, sizeof(format) / sizeof(CommandLineFormat), &args);
    }
    catch (...) {
    }
    parser.getOption(0, &firstKey);

    // Check if need to start additional application that packed into tvnserver.exe.

    if (firstKey.isEqualTo(TvnService::SERVICE_COMMAND_LINE_KEY)) {
        TvnService tvnService(&winEventLogWriter, &winEventLogWriter);
        try {
            crashHook.setHklmRoot();
            tvnService.run();
        }
        catch (Exception&) {
            return 1;
        }
        return 0;
    }
    else if (firstKey.isEqualTo(ControlCommandLine::CONFIG_APPLICATION) ||
        firstKey.isEqualTo(ControlCommandLine::CONFIG_SERVICE) ||
        firstKey.isEqualTo(ControlCommandLine::SET_CONTROL_PASSWORD) ||
        firstKey.isEqualTo(ControlCommandLine::SET_PRIMARY_VNC_PASSWORD) ||
        firstKey.isEqualTo(ControlCommandLine::CONTROL_SERVICE) ||
        firstKey.isEqualTo(ControlCommandLine::CONTROL_APPLICATION) ||
        firstKey.isEqualTo(ControlCommandLine::CHECK_SERVICE_PASSWORDS)) {
        crashHook.setGuiEnabled();
        try {
            ControlApplication tvnControl(hInstance,
                WindowNames::WINDOW_CLASS_NAME,
                lpCmdLine);
            return tvnControl.run();
        }
        catch (Exception& fatalException) {
            MessageBox(0,
                fatalException.getMessage(),
                StringTable::getString(IDS_MBC_TVNCONTROL),
                MB_OK | MB_ICONERROR);
            return 1;
        }
    }
    else if (firstKey.isEqualTo(AdditionalActionApplication::LOCK_WORKSTATION_KEY) ||
        firstKey.isEqualTo(AdditionalActionApplication::LOGOUT_KEY)) {
        crashHook.setGuiEnabled();
        try {
            AdditionalActionApplication actionApp(hInstance,
                WindowNames::WINDOW_CLASS_NAME,
                lpCmdLine);
            return actionApp.run();
        }
        catch (SystemException& ex) {
            return ex.getErrorCode();
        }
    }
    else if (firstKey.isEqualTo(DesktopServerCommandLine::DESKTOP_SERVER_KEY)) {
        try {
            crashHook.setHklmRoot();
            WinCommandLineArgs args(lpCmdLine);
            DesktopServerApplication desktopServerApp(hInstance,
                WindowNames::WINDOW_CLASS_NAME,
                &args);

            int retCode = desktopServerApp.run();
            return retCode;
        }
        catch (...) {
            return 1;
        }
    }
    else if (firstKey.isEqualTo(QueryConnectionCommandLine::QUERY_CONNECTION)) {
        crashHook.setGuiEnabled();
        try {
            QueryConnectionApplication app(hInstance,
                WindowNames::WINDOW_CLASS_NAME,
                lpCmdLine);
            return app.run();
        }
        catch (...) {
            return 1;
        }
    }
    else if (firstKey.isEqualTo(ServiceControlCommandLine::INSTALL_SERVICE) ||
        firstKey.isEqualTo(ServiceControlCommandLine::REMOVE_SERVICE) ||
        firstKey.isEqualTo(ServiceControlCommandLine::REINSTALL_SERVICE) ||
        firstKey.isEqualTo(ServiceControlCommandLine::START_SERVICE) ||
        firstKey.isEqualTo(ServiceControlCommandLine::STOP_SERVICE)) {
        crashHook.setGuiEnabled();
        ServiceControlApplication tvnsc(hInstance,
            WindowNames::WINDOW_CLASS_NAME,
            lpCmdLine);
        return tvnsc.run();
    }

    // No additional applications, run TightVNC server as single application.
    crashHook.setGuiEnabled();
    TvnServerApplication tvnServer(hInstance,
        WindowNames::WINDOW_CLASS_NAME,
        lpCmdLine, &winEventLogWriter);

    return tvnServer.run();
}
