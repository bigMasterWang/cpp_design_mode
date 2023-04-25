QStringList args;
args.push_back("--dx11");
if (CCommandLine::Get(CommandType::BCommandUseGameConsole).toBool())
{
    args.push_back("--console");
}
args.push_back("--start=Python");
QString pyArgs;
QString pyArgItem;
#ifndef _DEBUG
pyArgs.append("release@true,");
#endif
pyArgs.append("type@client,subtype@plat_battle,");
pyArgItem = QString("language@%1,").arg(QLocale().name());
pyArgs.append(pyArgItem);
pyArgItem = QString("ip@%1,").arg(m_currentGameInfo.battle_ip);
pyArgs.append(pyArgItem);
pyArgItem = QString("port@%1,").arg(m_currentGameInfo.battle_port);
pyArgs.append(pyArgItem);
pyArgItem = QString("seckey@%1,").arg(m_currentGameInfo.secret_key);
pyArgs.append(pyArgItem);

auto userSettings = CBaseModel::Get()->userSettings();
pyArgItem = QString("full_screen@%1,").arg(userSettings->gameFullScreen() ? "true" : "false");
pyArgs.append(pyArgItem);
pyArgItem = QString("graphics_quality@%1,")
.arg(userSettings->getGraphicsQualityText(userSettings->gameGraphicsQuality()));
pyArgs.append(pyArgItem);
pyArgItem = QString("platform_pid@%1,").arg(QCoreApplication::applicationPid());
pyArgs.append(pyArgItem);
if (m_currentGameInfo.battle_type == Structs::BattleType::Kingdom)
{
    pyArgItem = QString("battlestr@%1").arg(m_currentGameInfo.map_level);
}
else
{
    pyArgItem = QString("battlestr@%1").arg(m_currentGameInfo.battle_str);
}

pyArgs.append(pyArgItem);
pyArgs = QString("--python-args=") + pyArgs;
args.push_back(pyArgs);