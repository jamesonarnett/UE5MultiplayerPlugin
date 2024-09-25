# UE5 Multiplayer Sessions Plugin

> This plugin is currently a work in progress.

The primary goal of this plugin is to streamline setting up multiplayer in any C++ Unreal Engine 5+ project. <br /> 
This project is currently using v5.4.4. As development continues, I aim to support Steam, Amazon, Epic Online Service (EOS), and potentially mobile platforms.

---
## Getting Started

### Initial Setup

1. If you do not have a current Unreal Engine 5.0+ C++ project, create one or skip to step 3. While the majority of this plugin can be used with blueprints, there are a few pieces that currently require C++.

2. With your project built, copy this source's entire `/Plugins` folder into the base directory (where Content and Source are located).
    - If you already have a plugins folder, copy the `/Plugins/MultiplayerSessions` folder into `/Plugins` instead.

3. Optionally, you can clone this entire project or, copy the other folders into your project's root directory as well. These contain the default game mode and a few other assets from the ThirdPersonCharacter UE starter (v5.4).

### Configuring Steams Online Subsystem

1. With your UE5 project open, go to Edit -> Plugins and search for "Online Subsystem Steam". Check "Enabled" and restart the editor.

2. Configure `DefaultEngine.ini` and `DefaultGame.ini`. For more detailed information, refer to:
    - [Steam Documentation](https://dev.epicgames.com/documentation/en-us/unreal-engine/online-subsystem-steam?application_version=4.27)


In `/Config` add the following at the bottom of your `DefaultEngine.ini` file:

```ini
[/Script/Engine.GameEngine]
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="OnlineSubsystemUtils.IpNetDriver")

[OnlineSubsystem]
DefaultPlatformService=Steam

[OnlineSubsystemSteam]
bEnabled=true
SteamDevAppId=480

; If you are NOT using sessions, add a semicolon to the line below
bInitServerOnClient=true

[/Script/OnlineSubsystemSteam.SteamNetDriver]
NetConnectionClassName="OnlineSubsystemSteam.SteamNetConnection"
```
> **Note:** Replace SteamDevAppId=480 with your AppID, or continue using 480 for testing (this is the SpaceWar game on Steam and a widely accepted practice).

Finally, add the following to the bottom of your `DefaultGame.ini` file:

```ini
[/Script/Engine.GameSession]
MaxPlayers=100
```
> **Note:**  MaxPlayers is set later in the Menu blueprint. If your game will require more than 100 connections, update this value as well.

## Updating Your Project

1. Close your editor (and code editor).
2. In your project's root directory, delete the `Binaries`, `Intermediate`, and `Saved` folders.
3. Select your `.uproject` file and "Generate Visual Studio project files".
4. Open the `.sln` file. You should see the Plugins folder in the Solution Explorer.
5. Open your UE project, go to Settings in the Solution Explorer, and enable "Show Plugin Content".
    - You should now have two additional folders: "MultiplayerSessions Content" and "MultiplayerSessions C++ Classes".

## Creating a Lobby Level

1. Create and save a Lobby level (and a Starting level if you haven't already).
    - Common practice is to save these in `/Content/Maps/<your_level_name>`.

2. Open your Starting level and its level blueprint.

3. Use "Create Widget" and connect it to the "Event BeginPlay" node.
    - In the "Create Widget" node, select "WBP_Menu" as the widget class.

4. Drag off the return value and call "MenuSetup".
    - Set the number of connections to your desired player count.
    - Choose the type of match.
    - Update the path to your lobby level.

> **Note:** The level path doesn't use the full path. Replace everything before and including `/Content/` with `/Game/` and omit the file extension. For example: `/Game/Maps/<your_level_name>`

## Play Testing Your Game

1. After adding a character for your players, or perhaps a few test objects to see the transition from Starting to Lobby map, package your game from the UE editor (Platforms -> [Your Platform] -> Package Project).

2. With Steam open, and you logged in, launch the game and create a session.

3. For multiplayer testing, if you have friends, or your moms cool, you can send them a copy of the packaged game. If you do not, then surely you have two computers to test with.
    - Ensure they're logged into their Steam accounts before launching the game. 
    - If you test alone, you still must have a second Steam account.

> **Important:** While testing make sure all computers are set to the same Steam download region (Steam -> Settings -> Downloads -> Download Region).

---

For any issues or questions, please open an issue in the project repository.