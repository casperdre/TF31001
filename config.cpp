// BIS basic defines
#define TEast 0
#define TWest 1
#define TGuerrila 2
#define TCivilian 3
#define TSideUnknown 4
#define TEnemy 5
#define TFriendly 6
#define TLogic 7

#define true 1
#define false 0

// type scope
#define private 0
#define protected 1
#define public 2

#define VSoft 0
#define VArmor 1
#define VAir 2

#define CanSeeRadar 1
#define CanSeeEye 2
#define CanSeeOptics 4
#define CanSeeEar 8
#define CanSeeCompass 16
#define CanSeeRadarC CanSeeRadar+CanSeeCompass
#define CanSeeAll 31
#define CanSeePeripheral 32

#define ReadAndWrite 0		//! any modifications enabled
#define ReadAndCreate 1		//! only adding new class members is allowed
#define ReadOnly 2		//! no modifications enabled
#define ReadOnlyVerified 3	//! no modifications enabled, CRC test applied

#define LockNo		0
#define LockCadet	1
#define LockYes		2

class cfgPatches
{
	class ou_air
	{
		units[] =
		{
			"ou_ch_46"
		};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {};
	};
};

class cfgVehicleClasses
{
	class ou_air
	{
		displayName = "OU Air";
	};
};

class cfgVehicles
{
	class AllVehicles;

	class Air : AllVehicles
	{
		class NewTurret;
		class ViewPilot;
	};

	class Helicopter : Air
	{
		class HitHull;
		class HitEngine;
		class HitAvionics;
		class HitVRotor;
		class HitHRotor;
		class HitMissiles;
		class HitRGlass;
		class HitLGlass;
		
		class ViewPilot : ViewPilot {};
		
		class Turrets
		{
			class MainTurret : NewTurret
			{
				class HitTurret;
				class HitGun;
			};
		};
		class AnimationSources;
	};
	class ou_ch_46e
	{
		selectionHRotorStill = "velka vrtule staticka";
		selectionHRotorMove = "velka vrtule blur";
		selectionVRotorStill = "mala vrtule staticka";
		selectionVRotorMove = "mala vrtule blur";
		displayName = "CH-46E";
		simulation = "helicopter";
		model = "\ou_air\models\ou_ch_46e.p3d";
		mapSize = 13;
		nameSound = "chopper";
		extCameraPosition[] = {0, 2.5, -25};
		soundEngine[] = {"\ou_air\sound\ch46engine.wss", 1, 1.000000};
		armor = 65;
		cost = 10000000;
		maxSpeed = 200;
		crew = "B_helicrew_F";
		typicalCargo[] = {"B_helicrew_F", "B_helicrew_F", "B_helicrew_F", "B_helicrew_F"};
		weapons[] = {"CMFlareLauncher"};
  		magazines[] = {"168Rnd_CMFlare_Chaff_Magazine"};
  		memoryPointCM[] = {"Flare_Launcher1","Flare_launcher2"};
		ejectDeadDriver = 0;
		ejectDeadCargo = 0;
		driverCompartments = 1;
		hasdriver = true;
		hasGunner = true;
		castCargoShadow = true;
		driverAction = "UH1Y_Pilot";
		driverInAction = "UH1Y_Pilot";
		cargoAction[] = {"UH1Y_Cargo02", "UH1Y_Cargo03", "UH1Y_Cargo03", "UH1Y_Cargo02", "UH1Y_Cargo01", "UH1Y_Cargo01", "UH1Y_Cargo01"};
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		transportSoldier = 26;
		occludeSoundsWhenIn = 0.562341;
		obstructSoundsWhenIn = 0.316228;
		minMainRotorDive = -6;
		maxMainRotorDive = 10;
		neutralMainRotorDive = -2.6;
		minBackRotorDive = -10;
		maxBackRotorDive = 6;
		neutralBackRotorDive = -2.6;
		gearRetracting = 1;
		gearUpTime = 3.33;
		gearDownTime = 2.0;
		landingSpeed = 50.0;
		crewVulnerable = 1.5;
		selectionFireAnim = "muzzleflash";
		damageResistance = 0.00593;
		memoryPointsGetInDriver = "pos_driver";
		memoryPointsGetInDriverDir = "pos_driver_dir";
		threat[] = {0, 0, 0};
		transportMaxWeapons = 100;
		transportMaxMagazines = 500;

		class UserActions
		{
			class Openramp
			{
				displayName = "Lower Ramp";
				position = "pos_action";
				radius = 7.500000;
				onlyForPlayer = false;
				condition = "this animationPhase 'ramp' < 0.5 AND (PLAYER == driver this)";
				statement = "this animate ['ramp', 1]";
			};
			class CloseDoors
			{
				displayName = "Raise Ramp";
				position = "pos_action";
				radius = 7.500000;
				onlyForPlayer = false;
				condition = "this animationPhase 'ramp' >= 0.5 AND (PLAYER == driver this)";
				statement = "this animate ['ramp', 0]";
			};
		};

		class AnimationSources
		{
			class Ramp // Should be the same as your selection name.
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 3;  //The animation period used for this controller.
				initPhase = 0;   //Initial phase when object is created. 0 = CLOSED
			};
		};

		class Turrets
		{

			class co_pilot: NewTurret
			{
				startEngine = true;
				outGunnerMayFire = true;
				primaryGunner = 0;
				commanding = -1;
				proxyIndex = 1;
				gunnerName = "Co-Pilot";
				memoryPointsGetInGunner = "pos_driver";
				memoryPointsGetInGunnerDir = "pos_driver_dir";
				gunnerAction = "UH1Y_Pilot";
				gunnerInAction = "UH1Y_Pilot";
				initTurn = 0;
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerForceOptics = false;
			};

		};

		class Reflectors
		{
			class Left
			{
				color[] = {0.8, 0.8, 1.0, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 1.0;
			};

			class Right
			{
				color[] = {0.8, 0.8, 1.0, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 1;
				brightness = 1.0;
			};
		};
		enum
		{ =
			  2,
		  destructengine = 2,
		  destructdefault = 6,
		  destructwreck = 7,
		  destructtree = 3,
		  destructtent = 4,
		  stabilizedinaxisx = 1,
		  stabilizedinaxisy = 2,
		  stabilizedinaxesboth = 3,
		  destructno = 0,
		  stabilizedinaxesnone = 0,
		  destructman = 5,
		  destructbuilding = 1
		};

		class EventHandlers
		{
			GetIn = "_this exec '\ou_air\scripts\rampin.sqs'";
			GetOut = "_this exec '\ou_air\scripts\rampin.sqs'";
		};
	};
};
