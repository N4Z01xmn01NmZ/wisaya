#include <wisaya/core/logger.hpp>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>


namespace Wisaya {

    shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    void Logger::Initialize() {
        std::vector<spdlog::sink_ptr> consoleSink;
        consoleSink.emplace_back(makeShared<spdlog::sinks::stdout_color_sink_mt>());
        consoleSink[0]->set_pattern("%^[%T.%e] %n: %v%$");
        
        s_CoreLogger = makeShared<spdlog::logger>(
            "WISAYA",
            std::begin(consoleSink),
            std::end(consoleSink)
        );
        s_CoreLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_CoreLogger);
        
        s_ClientLogger = makeShared<spdlog::logger>(
            "CLIENT",
            std::begin(consoleSink),
            std::end(consoleSink)
        );
        s_ClientLogger->set_level(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_ClientLogger);
    }

    void Logger::Shutdown() {
        spdlog::shutdown();
    }

} // namespace Wisaya
