void mirfSetup()
{
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"pir01"); // adress of the antenna
  Mirf.payload = 1;
  // Mirf.channel = 10; // to change the channel if necessary
  Mirf.config();
}
