void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer

{
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 1, true);
	}

	EntityAI srsClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_SRSA2");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_SRSA2_10rnd");
		addMags(player, "Rev_Mag_SRSA2_10rnd", 8);
		return gun;
	}

	EntityAI dvlClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("CPB_DVLSup_Black");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("CPB_DVL_Magazine");
		addMags(player, "CPB_DVL_Magazine", 8);
		return gun;
	}

	EntityAI remiClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M2010_Blue");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_M2010_10rnd");
		addMags(player, "Rev_Mag_M2010_10rnd", 8);
		return gun;
	}

	EntityAI sakoClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_SAKOTRG");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("BO_Mag_SAKOTRG_5rnd");
		addMags(player, "BO_Mag_SAKOTRG_5rnd", 8);
		return gun;
	}

	EntityAI deltaClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_Delta5_Camo4");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("BO_Mag_Delta5_10rnd");
		addMags(player, "BO_Mag_Delta5_10rnd", 8);
		return gun;
	}

	EntityAI m200Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M200");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_M200_7rnd");
		addMags(player, "Rev_Mag_M200_7rnd", 8);
		return gun;
	}

	EntityAI m300Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_M300");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("BO_Mag_M300_7rnd");
		addMags(player, "BO_Mag_M300_7rnd", 8);
		return gun;
	}

	EntityAI msrClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("PITSTOP_MSR");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("PITSTOP_MSR_Magazine");
		addMags(player, "PITSTOP_MSR_Magazine", 8);
		return gun;
	}

	EntityAI m96Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_M96");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("BO_Mag_M96_5rnd");
		addMags(player, "BO_Mag_M96_5rnd", 8);
		return gun;
	}

	EntityAI cdxClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_CDX50");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_CDX50_5rnd");
		addMags(player, "Rev_Mag_CDX50_5rnd", 8);
		return gun;
	}

	EntityAI axClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("SNAFUAX50_GUN");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("SNAFUAX50_Mag");
		addMags(player, "SNAFUAX50_Mag", 8);
		return gun;
	}

	EntityAI gatorClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("SNAFUAlligator");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("SNAFUAlligator_5rndMag");
		addMags(player, "SNAFUAlligator_5rndMag", 6);
		return gun;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		player.GetInventory().CreateInInventory("Mz_W_Hexgrid_Black");
		player.GetInventory().CreateInInventory("EFT_bag_Kakashka");
		player.GetInventory().CreateInInventory("MedicalScrubsShirt_White");
		player.GetInventory().CreateInInventory("PITSTOP_SOCOMPants_Black");
		player.GetInventory().CreateInInventory("PITSTOP2_SOCOMBelt_Black");
		player.GetInventory().CreateInInventory("PITSTOP_AirForce_Black");
		player.GetInventory().CreateInInventory("BalaclavaMask_Blackskull");
		player.GetInventory().CreateInInventory("PITSTOP2_MechanixGloves_Black");
		player.GetInventory().CreateInInventory("Black_CamoNetPoncho");
		player.GetInventory().CreateInInventory("PITSTOP2_RysHelmet_Black");
		player.GetInventory().CreateInInventory("HuntingKnife");
		player.GetInventory().CreateInInventory("SalineBagIV");
		player.GetInventory().CreateInInventory("SalineBagIV");
		ItemBase bandage = player.GetInventory().CreateInInventory("BandageDressing");
		ItemBase meds1 = player.GetInventory().CreateInInventory("SalineBagIV");
		ItemBase meds2 = player.GetInventory().CreateInInventory("SalineBagIV");
		ItemBase meds3 = player.GetInventory().CreateInInventory("SalineBagIV");
		ItemBase meds4 = player.GetInventory().CreateInInventory("SalineBagIV");
		ItemBase meds5 = player.GetInventory().CreateInInventory("SalineBagIV");
		ItemBase meds6 = player.GetInventory().CreateInInventory("SalineBagIV");

		EntityAI primary;

		switch (Math.RandomInt(0, 11)) {
			case 0: primary = srsClass(player); break;
			case 1: primary = dvlClass(player); break;
			case 2: primary = remiClass(player); break;
			case 3: primary = sakoClass(player); break;
			case 4: primary = deltaClass(player); break;
			case 5: primary = m200Class(player); break;
			case 6: primary = m300Class(player); break;
			case 7: primary = msrClass(player); break;
			case 8: primary = m96Class(player); break;
			case 9: primary = cdxClass(player); break;
			case 10: primary = axClass(player); break;
			case 11: primary = gatorClass(player); break;
		}

		player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);
		player.SetQuickBarEntityShortcut(bandage, 1, true);
		player.SetQuickBarEntityShortcut(meds1, 2, true);
		player.SetQuickBarEntityShortcut(meds2, 3, true);
		player.SetQuickBarEntityShortcut(meds3, 4, true);
		player.SetQuickBarEntityShortcut(meds4, 5, true);
		player.SetQuickBarEntityShortcut(meds5, 6, true);
		player.SetQuickBarEntityShortcut(meds6, 7, true);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
