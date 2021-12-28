#include <Wisaya_pch.hpp>
#include <wisaya/core/WAppLog.hpp>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>


namespace Wisaya {

    reference_ptr<spdlog::logger> WAppLog::s_CoreLogger;
    reference_ptr<spdlog::logger> WAppLog::s_ClientLogger;

    void WAppLog::Initialize() {
        std::vector<spdlog::sink_ptr> consoleSink;
        consoleSink.emplace_back(create_reference<spdlog::sinks::stdout_color_sink_mt>());
        consoleSink[0]->set_pattern("%^[%T.%e] %n: %v%$");
        
        s_CoreLogger = create_reference<spdlog::logger>(
            "WISAYA",
            std::begin(consoleSink),
            std::end(consoleSink)
        );
        s_CoreLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_CoreLogger);
        
        s_ClientLogger = create_reference<spdlog::logger>(
            "CLIENT",
            std::begin(consoleSink),
            std::end(consoleSink)
        );
        s_ClientLogger->set_level(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_ClientLogger);
    }

    void WAppLog::Shutdown() {
        spdlog::shutdown();
    }

} // namespace Wisaya
